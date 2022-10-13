#include <cstdlib>
#include "json.hpp"
#include "webview.h"

#include "bundle.h"

using json = nlohmann::json;

webview::webview w(false, nullptr);

std::string GeneratePassword(std::string args){

    std::string numbers = "0123456789";
    std::string low_symbols = "abcdefghijklmnopqrstuvwxyz";
    std::string up_symbols = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string spec_symbols = "+-/*!&$#?=@<>";

    std::string res = "";
    std::string ret = "";

    json j = json::parse(args);

    if (j[0].get<bool>()) res += numbers;
    if (j[1].get<bool>()) res += low_symbols;
    if (j[2].get<bool>()) res += up_symbols;
    if (j[3].get<bool>()) res += spec_symbols;

    srand(time(0));

    for (std::uint16_t i = 0; i < j[4].get<std::uint16_t>(); ++i){

        ret += res[std::uint16_t(rand() % res.length())];

    }

    return "\"" + ret + "\"";

}

int main(int argc, char* argv[]) {

    w.set_title("Password Generator");
    w.set_size(300, 400, WEBVIEW_HINT_NONE);
    w.set_html(reinterpret_cast<char*>(bundle_html));
    w.bind("GeneratePassword", GeneratePassword);
    w.run();

    return 0;

} 
