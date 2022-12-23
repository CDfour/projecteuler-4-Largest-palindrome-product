#include "largest_palindrome_product.h"

#include <stdexcept>

bool hundred_thousand_palindrome(int value) {

    if (value > 99999) {

        int units = value % 10;
        int tens = ((value - units) / 10) % 10;
        int hundreds = ((value - tens * 10 - units) / 100) % 10;
        int thousands = ((value - hundreds * 100 - tens * 10 - units) / 1000) % 10;
        int tensOfThousands = ((value - thousands * 1000 - hundreds * 100 - tens * 10 - units) / 10000) % 10;
        int hundredsOfThousands = ((value - tensOfThousands * 10000 - thousands * 1000 - hundreds * 100 - tens * 10 - units) / 100000) % 10;

        return units == hundredsOfThousands && tens == tensOfThousands && hundreds == thousands;
    }

    throw std::invalid_argument("only hundreds of thousands are accepted");
}

// answer = 906609
int largest_palindrome_product() {

    for (int i = 999; ; --i) {

        for (int j = i; j > 901; --j) {

            int value = i * j;
            if (hundred_thousand_palindrome(value)) {
                return value;
            }
        }
    }
}