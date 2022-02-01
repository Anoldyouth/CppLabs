#define _CRT_SECURE_NO_WARNINGS
#define CURL_STATICLIB
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <curl/curl.h>
#include <regex>
#include <fstream>
#include <codecvt>
#include <cctype>
#include <iomanip>
#include <sstream>

using namespace std;

string urlEncode(string str) {
    string new_str = "";
    char c;
    int ic;
    const char* chars = str.c_str();
    char bufHex[10];
    int len = strlen(chars);

    for (int i = 0;i < len;i++) {
        c = chars[i];
        switch (c) 
        {
        case('а'): {new_str += "%D0%B0"; break;}
        case('А'): {new_str += "%D0%90"; break;}
        
        case('б'): {new_str += "%D0%B1"; break;}
        case('Б'): {new_str += "%D0%91"; break;}

        case('в'): {new_str += "%D0%B2"; break;}
        case('В'): {new_str += "%D0%92"; break;}

        case('г'): {new_str += "%D0%B3"; break;}
        case('Г'): {new_str += "%D0%93"; break;}

        case('д'): {new_str += "%D0%B4"; break;}
        case('Д'): {new_str += "%D0%94"; break;}

        case('е'): {new_str += "%D0%B5"; break;}
        case('Е'): {new_str += "%D0%95"; break;}

        case('ё'): {new_str += "%D1%91"; break;}
        case('Ё'): {new_str += "%D0%81"; break;}

        case('ж'): {new_str += "%D0%B6"; break;}
        case('Ж'): {new_str += "%D0%96"; break;}

        case('з'): {new_str += "%D0%B7"; break;}
        case('З'): {new_str += "%D0%97"; break;}

        case('к'): {new_str += "%D0%BA"; break;}
        case('К'): {new_str += "%D0%9A"; break;}

        case('л'): {new_str += "%D0%BB"; break;}
        case('Л'): {new_str += "%D0%9B"; break;}

        case('м'): {new_str += "%D0%BC"; break;}
        case('М'): {new_str += "%D0%9C"; break;}

        case('н'): {new_str += "%D0%BD"; break;}
        case('Н'): {new_str += "%D0%9D"; break;}

        case('о'): {new_str += "%D0%BE"; break;}
        case('О'): {new_str += "%D0%9E"; break;}

        case('п'): {new_str += "%D0%BF"; break;}
        case('П'): {new_str += "%D0%9F"; break;}

        case('р'): {new_str += "%D1%80"; break;}
        case('Р'): {new_str += "%D0%A0"; break;}

        case('с'): {new_str += "%D1%81"; break;}
        case('С'): {new_str += "%D0%A1"; break;}

        case('т'): {new_str += "%D1%82"; break;}
        case('Т'): {new_str += "%D0%A2"; break;}

        case('у'): {new_str += "%D1%83"; break;}
        case('У'): {new_str += "%D0%A3"; break;}

        case('ф'): {new_str += "%D1%84"; break;}
        case('Ф'): {new_str += "%D0%A4"; break;}

        case('ц'): {new_str += "%D1%86"; break;}
        case('Ц'): {new_str += "%D0%A6"; break;}

        case('ш'): {new_str += "%D1%88"; break;}
        case('Ш'): {new_str += "%D0%A8"; break;}

        case('щ'): {new_str += "%D1%89"; break;}
        case('Щ'): {new_str += "%D0%A9"; break;}

        case('и'): {new_str += "%D0%B8"; break;}
        case('И'): {new_str += "%D0%98"; break;}

        case('й'): {new_str += "%D0%B9"; break;}
        case('Й'): {new_str += "%D0%99"; break;}

        case('ъ'): {new_str += "%D1%8A"; break;}
        case('Ъ'): {new_str += "%D0%AA"; break;}

        case('ы'): {new_str += "%D1%8B"; break;}
        case('Ы'): {new_str += "%D0%AB"; break;}

        case('ь'): {new_str += "%D1%8C"; break;}
        case('Ь'): {new_str += "%D0%AC"; break;}

        case('э'): {new_str += "%D1%8D"; break;}
        case('Э'): {new_str += "%D0%AD"; break;}

        case('ю'): {new_str += "%D1%8E"; break;}
        case('Ю'): {new_str += "%D0%AE"; break;}

        case('я'): {new_str += "%D1%8F"; break;}
        case('Я'): {new_str += "%D0%AF"; break;}

        case('х'): {new_str += "%D1%85"; break;}
        case('Х'): {new_str += "%D0%A5"; break;}

        case('ч'): {new_str += "%D1%87"; break;}
        case('Ч'): {new_str += "%D0%A7"; break;}

        case('і'): {new_str += "%D1%96"; break;}
        case('І'): {new_str += "%D0%86"; break;}

        case('ў'): {new_str += "%D1%9E"; break;}
        case('Ў'): {new_str += "%D0%8E"; break;}

        case('='): {new_str += "%3D"; break;}
        case('+'): {new_str += "%2B"; break;}
        case('@'): {new_str += "%40"; break;}
        case('"'): {new_str += "%22"; break;}
        case(' '): {new_str += "%20"; break;}
        case(','): {new_str += "%2C"; break;}
        case(';'): {new_str += "%3B"; break;}
        case('#'): {new_str += "%23"; break;}
        case('№'): {new_str += "%E2%84%96"; break;}
        case('$'): {new_str += "%24"; break;}
        case('%'): {new_str += "%25"; break;}
        case('^'): {new_str += "%5E"; break;}
        case(':'): {new_str += "%3A"; break;}
        case('&'): {new_str += "%26"; break;}
        case('?'): {new_str += "%3F"; break;}
        case('{'): {new_str += "%7B"; break;}
        case('}'): {new_str += "%7D"; break;}
        case('['): {new_str += "%5B"; break;}
        case(']'): {new_str += "%5D"; break;}
        case('/'): {new_str += "%2F"; break;}
        case('<'): {new_str += "%3C"; break;}
        case('>'): {new_str += "%3E"; break;}
        case('\\'): {new_str += "%5C"; break;}
        case('|'): {new_str += "%7C"; break;}
        default:
        {
            new_str += c;
        }
        }
        
    }
    return new_str;
}

string utf8_to_string(const char* utf8str, const locale& loc)
{
    // UTF-8 to wstring
    wstring_convert<codecvt_utf8<wchar_t>> wconv;
    wstring wstr = wconv.from_bytes(utf8str);
    // wstring to string
    vector<char> buf(wstr.size());
    use_facet<ctype<wchar_t>>(loc).narrow(wstr.data(), wstr.data() + wstr.size(), '?', buf.data());
    return string(buf.data(), buf.size());
}

size_t writefunc(void* ptr, size_t size, size_t nmemb, std::string* s)
{
    s->append(static_cast<char*>(ptr), size * nmemb);
    return size * nmemb;
}

void be2ru(const string &input_text) 
{
    CURL* hnd = curl_easy_init();
    string text;
    string url = "https://nlp-translation.p.rapidapi.com/v1/translate?text=" + urlEncode(input_text) + "&to=ru&from=be";
    curl_easy_setopt(hnd, CURLOPT_CUSTOMREQUEST, "GET");
    curl_easy_setopt(hnd, CURLOPT_URL, url.c_str());

    struct curl_slist* headers = NULL;
    headers = curl_slist_append(headers, "x-rapidapi-host: nlp-translation.p.rapidapi.com");
    headers = curl_slist_append(headers, "x-rapidapi-key: db11d6deaemshc87e76dd4e615b6p1f35e0jsn4ab8e994acf6");
    curl_easy_setopt(hnd, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(hnd, CURLOPT_WRITEFUNCTION, writefunc);
    curl_easy_setopt(hnd, CURLOPT_WRITEDATA, &text);
    CURLcode ret = curl_easy_perform(hnd);
    string str;
    smatch result;

    regex translated("\"translated_text\":\\{\"ru\":\".*\"\\}");
    regex_search(text, result, translated);

    string text1 = result[0];

    regex translated2("\"ru\":\".*\"");
    regex_search(text1, result, translated2);
    string text2 = result[0];
    regex translated3(":\".*\"");
    regex_search(text2, result, translated3);
    string result_text = result[0];
    result_text[0] = ' '; result_text[1] = ' '; result_text[result_text.length() - 1] = ' ';

    string ansi_result = utf8_to_string(result_text.c_str(), locale(".1251"));
    cout << "Исходный текст на белорусском: " << input_text << endl;
    cout << "Перевод на русском:" << ansi_result << endl;
}

void ru2be(string input_text)
{
    CURL* hnd = curl_easy_init();
    string text;
    string url = "https://nlp-translation.p.rapidapi.com/v1/translate?text=" + urlEncode(input_text) + "&to=be&from=ru";
    curl_easy_setopt(hnd, CURLOPT_CUSTOMREQUEST, "GET");
    curl_easy_setopt(hnd, CURLOPT_URL, url.c_str());

    struct curl_slist* headers = NULL;
    headers = curl_slist_append(headers, "x-rapidapi-host: nlp-translation.p.rapidapi.com");
    headers = curl_slist_append(headers, "x-rapidapi-key: db11d6deaemshc87e76dd4e615b6p1f35e0jsn4ab8e994acf6");
    curl_easy_setopt(hnd, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(hnd, CURLOPT_WRITEFUNCTION, writefunc);
    curl_easy_setopt(hnd, CURLOPT_WRITEDATA, &text);
    CURLcode ret = curl_easy_perform(hnd);
    string str;
    smatch result;
    
    regex translated("\"translated_text\":\\{\"be\":\".*\"\\}");
    regex_search(text, result, translated);

    string text1 = result[0];

    regex translated2("\"be\":\".*\"");
    regex_search(text1, result, translated2);
    string text2 = result[0];
    regex translated3(":\".*\"");
    regex_search(text2, result, translated3);
    string result_text = result[0];
    result_text[0] = ' '; result_text[1] = ' '; result_text[result_text.length()-1] = ' ';

    string ansi_result = utf8_to_string(result_text.c_str(), locale(".1251"));
    cout << "Исходный текст на русском: " << input_text << endl;
    cout << "Перевод на белорусском:" << ansi_result << endl;
}

void main() {
    system("chcp 1251");
    string text;
    cout << "1) Перевести с русского на белорусский" << endl;
    cout << "2) Перевести с белорусского на русский" << endl;
    cout << "Выберите пункт: ";
    int count;
    cin >> count;
    switch (count)
    {
    case(1):
    {
        while (fgetc(stdin) != '\n');
        cout << "Введите, что надо перевести: ";
        string input_text;
        getline(std::cin, input_text);
        ru2be(input_text);
        break;
    }
    case(2): 
    {
        while (fgetc(stdin) != '\n');
        cout << "Введите, что надо перевести: ";
        string input_text;
        getline(std::cin, input_text);
        be2ru(input_text);
        break;
    }
    default:
    {
        cout << "Неправильный пункт меню" << endl;
    }
    }

}