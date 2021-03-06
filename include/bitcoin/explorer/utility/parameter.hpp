/**
 * Copyright (c) 2011-2014 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin-explorer.
 *
 * libbitcoin-explorer is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License with
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
#ifndef PARAMETER_HPP
#define PARAMETER_HPP

#include <string>
#include <utility>
#include <vector>
#include <boost/program_options.hpp>
#include <bitcoin/explorer/define.hpp>
#include <bitcoin/explorer/utility/utility.hpp>

/* NOTE: don't declare 'using namespace foo' in headers. */

namespace libbitcoin {
namespace explorer {

#define PROPERTY(type, name) \
    public: virtual type get_##name() const { return name##_; } \
    public: virtual void set_##name(type value) { name##_ = value; } \
    private: type name##_

/**
 * A tuple to represent a positional argument name count.
 */
typedef std::pair<const std::string, int> argument_pair;

/**
 * A type to represent the list of positional argument name counts.
 */
typedef std::vector<argument_pair> argument_list;

/**
 * A type to represent a list of parameter structures.
 */
class parameter;
typedef std::vector<parameter> parameter_list;

/**
 * Normalized storage for command line arguments and options.
 * TEST: option_metadata does not provide virtual methods so must wrap to mock.
 */
class parameter
{
private:

    /**
     * Enumerated options for selecting the canonical name.
     */
    enum search_options : int
    {
        /** --name/-n */
        dashed_both_prefer_long = 1,

        /** name/-n */
        dashed_short_prefer_long = 2,

        /** -n/name */
        dashed_short_prefer_short = 4
    };

public:

    /**
     * Sentinel - the option is not a positional argument.
     */
    BCX_API static const int not_positional;

    /**
     * Sentinel - there is no short name.
     */
    BCX_API static const char no_short_name;

    /**
     * The character used to prefix command line options.
     */
    BCX_API static const char option_prefix_char;

    /**
     * Populate with normalized parameter data.
     * @param[in]  option     The metadata of the option to test.
     * @param[in]  arguments  The list of supported positional arguments.
     */
    BCX_API virtual void initialize(const option_metadata& option,
        const argument_list& arguments);

    /**
     * Determine if the option is an argument by testing for it by name in the 
     * positional options collection and if so return the position.
     * @param[in]  option     The metadata of the option to position.
     * @param[in]  arguments  The list of supported positional arguments.
     * @return                Relative position or -1 if not positional.
     */
    BCX_API virtual int position(const option_metadata& option,
        const argument_list& arguments) const;

    /**
     * Get the value for the args_limit property.
     * @param[in]  position   The option's position (or -1 of arg).
     * @param[in]  option     The option.
     * @param[in]  arguments  The argument names list.
     * @return                The arguments limit value for the option.
     */
    BCX_API unsigned arguments_limit(int position, 
        const option_metadata& option, const argument_list& arguments) const;

    /**
     * Get the option's short name character or zero.
     * @param[in]  option  The metadata of the option to test.
     * @return             The short name character or null character.
     */
    BCX_API virtual char short_name(const option_metadata& option) const;

    /**
     * Virtual property declarations.
     */
    PROPERTY(int, position);
    PROPERTY(bool, required);
    PROPERTY(char, short_name);
    PROPERTY(unsigned, args_limit);
    PROPERTY(std::string, long_name);
    PROPERTY(std::string, description);
    PROPERTY(std::string, format_name);
    PROPERTY(std::string, format_parameter);
};

} // namespace explorer
} // namespace libbitcoin

#endif