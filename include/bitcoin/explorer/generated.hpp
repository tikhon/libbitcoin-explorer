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
#ifndef BX_GENERATED_HPP
#define BX_GENERATED_HPP

#include <functional>
#include <memory>
#include <string>
#include <bitcoin/explorer/command.hpp>
#include <bitcoin/explorer/commands/address-decode.hpp>
#include <bitcoin/explorer/commands/address-embed.hpp>
#include <bitcoin/explorer/commands/address-encode.hpp>
#include <bitcoin/explorer/commands/address-validate.hpp>
#include <bitcoin/explorer/commands/base16-decode.hpp>
#include <bitcoin/explorer/commands/base16-encode.hpp>
#include <bitcoin/explorer/commands/base58-decode.hpp>
#include <bitcoin/explorer/commands/base58-encode.hpp>
#include <bitcoin/explorer/commands/base58check-decode.hpp>
#include <bitcoin/explorer/commands/base58check-encode.hpp>
#include <bitcoin/explorer/commands/bci-fetch-last-height.hpp>
#include <bitcoin/explorer/commands/bci-history.hpp>
#include <bitcoin/explorer/commands/bitcoin160.hpp>
#include <bitcoin/explorer/commands/bitcoin256.hpp>
#include <bitcoin/explorer/commands/blke-fetch-transaction.hpp>
#include <bitcoin/explorer/commands/btc-to-satoshi.hpp>
#include <bitcoin/explorer/commands/ec-add.hpp>
#include <bitcoin/explorer/commands/ec-add-secrets.hpp>
#include <bitcoin/explorer/commands/ec-lock.hpp>
#include <bitcoin/explorer/commands/ec-multiply.hpp>
#include <bitcoin/explorer/commands/ec-multiply-secrets.hpp>
#include <bitcoin/explorer/commands/ec-new.hpp>
#include <bitcoin/explorer/commands/ec-to-address.hpp>
#include <bitcoin/explorer/commands/ec-to-public.hpp>
#include <bitcoin/explorer/commands/ec-to-wif.hpp>
#include <bitcoin/explorer/commands/ec-unlock.hpp>
#include <bitcoin/explorer/commands/fetch-balance.hpp>
#include <bitcoin/explorer/commands/fetch-header.hpp>
#include <bitcoin/explorer/commands/fetch-height.hpp>
#include <bitcoin/explorer/commands/fetch-history.hpp>
#include <bitcoin/explorer/commands/fetch-public-key.hpp>
#include <bitcoin/explorer/commands/fetch-stealth.hpp>
#include <bitcoin/explorer/commands/fetch-tx.hpp>
#include <bitcoin/explorer/commands/fetch-tx-index.hpp>
#include <bitcoin/explorer/commands/fetch-utxo.hpp>
#include <bitcoin/explorer/commands/genaddr.hpp>
#include <bitcoin/explorer/commands/genpriv.hpp>
#include <bitcoin/explorer/commands/genpub.hpp>
#include <bitcoin/explorer/commands/hd-new.hpp>
#include <bitcoin/explorer/commands/hd-private.hpp>
#include <bitcoin/explorer/commands/hd-public.hpp>
#include <bitcoin/explorer/commands/hd-to-address.hpp>
#include <bitcoin/explorer/commands/hd-to-ec.hpp>
#include <bitcoin/explorer/commands/hd-to-public.hpp>
#include <bitcoin/explorer/commands/hd-to-wif.hpp>
#include <bitcoin/explorer/commands/help.hpp>
#include <bitcoin/explorer/commands/initchain.hpp>
#include <bitcoin/explorer/commands/input-set.hpp>
#include <bitcoin/explorer/commands/input-sign.hpp>
#include <bitcoin/explorer/commands/input-validate.hpp>
#include <bitcoin/explorer/commands/mnemonic-decode.hpp>
#include <bitcoin/explorer/commands/mnemonic-encode.hpp>
#include <bitcoin/explorer/commands/mpk.hpp>
#include <bitcoin/explorer/commands/newseed.hpp>
#include <bitcoin/explorer/commands/qrcode.hpp>
#include <bitcoin/explorer/commands/ripemd160.hpp>
#include <bitcoin/explorer/commands/satoshi-to-btc.hpp>
#include <bitcoin/explorer/commands/script-decode.hpp>
#include <bitcoin/explorer/commands/script-encode.hpp>
#include <bitcoin/explorer/commands/script-to-address.hpp>
#include <bitcoin/explorer/commands/seed.hpp>
#include <bitcoin/explorer/commands/send-tx.hpp>
#include <bitcoin/explorer/commands/send-tx-node.hpp>
#include <bitcoin/explorer/commands/send-tx-p2p.hpp>
#include <bitcoin/explorer/commands/sendtx-bci.hpp>
#include <bitcoin/explorer/commands/settings.hpp>
#include <bitcoin/explorer/commands/sha160.hpp>
#include <bitcoin/explorer/commands/sha256.hpp>
#include <bitcoin/explorer/commands/sha512.hpp>
#include <bitcoin/explorer/commands/showblkhead.hpp>
#include <bitcoin/explorer/commands/stealth-decode.hpp>
#include <bitcoin/explorer/commands/stealth-encode.hpp>
#include <bitcoin/explorer/commands/stealth-initiate.hpp>
#include <bitcoin/explorer/commands/stealth-newkey.hpp>
#include <bitcoin/explorer/commands/stealth-public.hpp>
#include <bitcoin/explorer/commands/stealth-secret.hpp>
#include <bitcoin/explorer/commands/stealth-shared.hpp>
#include <bitcoin/explorer/commands/tx-decode.hpp>
#include <bitcoin/explorer/commands/tx-encode.hpp>
#include <bitcoin/explorer/commands/tx-sign.hpp>
#include <bitcoin/explorer/commands/uri-decode.hpp>
#include <bitcoin/explorer/commands/uri-encode.hpp>
#include <bitcoin/explorer/commands/validate-tx.hpp>
#include <bitcoin/explorer/commands/wallet.hpp>
#include <bitcoin/explorer/commands/watch-address.hpp>
#include <bitcoin/explorer/commands/watch-tx.hpp>
#include <bitcoin/explorer/commands/wif-to-ec.hpp>
#include <bitcoin/explorer/commands/wif-to-public.hpp>
#include <bitcoin/explorer/commands/wrap-decode.hpp>
#include <bitcoin/explorer/commands/wrap-encode.hpp>
#include <bitcoin/explorer/define.hpp>

/********* GENERATED SOURCE CODE, DO NOT EDIT EXCEPT EXPERIMENTALLY **********/

namespace libbitcoin {
namespace explorer {

/**
 * Various shared localizable strings.
 */
#define BX_COMMANDS_HEADER \
    "Info: The bx commands are:"
#define BX_COMMANDS_HOME_PAGE \
    "Bitcoin Explorer home page:"
#define BX_COMMAND_USAGE \
    "Usage: bx COMMAND [--help]"
#define BX_CONFIG_DESCRIPTION \
    "The path to the configuration settings file."
#define BX_CONNECTION_FAILURE \
    "Could not connect to server: %1%"
#define BX_DEPRECATED_COMMAND \
    "The '%1%' command has been replaced by '%2%'."
#define BX_HELP_DESCRIPTION \
    "Get a description and instructions for this command."
#define BX_INVALID_COMMAND \
    "'%1%' is not a bx command. Enter 'bx help' for a list of commands."
#define BX_INVALID_PARAMETER \
    "Error: %1%"
#define BX_PRINTER_ARGUMENT_TABLE_HEADER \
    "Arguments (positional):"
#define BX_PRINTER_DESCRIPTION_FORMAT \
    "Info: %1%"
#define BX_PRINTER_OPTION_TABLE_HEADER \
    "Options (named):"
#define BX_PRINTER_USAGE_FORMAT \
    "Usage: %1% %2% %3%"
#define BX_PRINTER_VALUE_TEXT \
    "VALUE"
#define BX_UNEXPECTED_EXCEPTION \
    "Unexpected error: %1%"

/**
 * Invoke a specified function on all commands.
 * @param[in]  func  The function to invoke on all commands.
 */
BCX_API void broadcast(
    const std::function<void(std::shared_ptr<command>)> func);

/**
 * Find the command identified by the specified symbolic command name.
 * @param[in]  symbol  The symbolic command name.
 * @return             An instance of the command or nullptr if not found.
 */
BCX_API std::shared_ptr<command> find(const std::string& symbol);

/**
 * Find the new name of the formerly-named command.
 * @param[in]  former  The former symbolic command name.
 * @return             The current name of the formerly-named command.
 */
BCX_API std::string formerly(const std::string& former);

} // namespace explorer
} // namespace libbitcoin

#endif
