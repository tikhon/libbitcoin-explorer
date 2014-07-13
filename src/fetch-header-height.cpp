/**
 * Copyright (c) 2011-2014 sx developers (see AUTHORS)
 *
 * This file is part of sx.
 *
 * sx is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include <sx/command/fetch-header-height.hpp>

#include <iostream>
#include <bitcoin/bitcoin.hpp>
#include <obelisk/obelisk.hpp>
#include <sx/obelisk.hpp>
#include <sx/utility/console.hpp>

using namespace bc;
using namespace sx;
using namespace sx::extension;

// TODO: this should be a member of sx::extensions::fetch_header_height,
// otherwise concurrent test execution will collide on shared state.
static bool node_stopped = false;

// TODO: node_stopped should be passed here via closure
// or by converting this to a member function.
static void height_header_fetched(const std::error_code& error,
    const block_header_type& block_header)
{
    if (error)
        std::cerr << error.message() << std::endl;
    else
    {
        data_chunk raw_block_header(satoshi_raw_size(block_header));
        satoshi_save(block_header, raw_block_header.begin());

        std::cout << raw_block_header << std::endl;
    }

    node_stopped = true;
}

console_result fetch_header_height::invoke(std::istream& input,
    std::ostream& output, std::ostream& cerr)
{
    // Bound parameters.
    auto height = get_height_argument();

    OBELISK_FULLNODE(pool, fullnode);
    fullnode.blockchain.fetch_block_header(height, height_header_fetched);
    poll(fullnode, pool, node_stopped);
    return console_result::okay;
}
