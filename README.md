# Open Authenticator component

[![SRA Board component](https://github.com/Open-Authenticator/open-authenticator-component/actions/workflows/test-build-apps.yaml/badge.svg)](https://github.com/Open-Authenticator/open-authenticator-component/actions/workflows/test-build-apps.yaml)
[![GitHub issues](https://img.shields.io/github/issues/Open-Authenticator/open-authenticator-component)](https://github.com/Open-Authenticator/open-authenticator-component/issues)
[![GitHub forks](https://img.shields.io/github/forks/Open-Authenticator/open-authenticator-component)](https://github.com/Open-Authenticator/open-authenticator-component/network)
[![GitHub stars](https://img.shields.io/github/stars/Open-Authenticator/open-authenticator-component)](https://github.com/Open-Authenticator/open-authenticator-component/stargazers)
[![GitHub license](https://img.shields.io/github/license/Open-Authenticator/open-authenticator-component)](https://github.com/Open-Authenticator/open-authenticator-component/blob/master/LICENSE)

#### ESP-IDF component for peripherals on Open Authenticator board.

* Functions to read battery voltage and battery percentage
* Functions to control the load switch which powers OLED and RTC on Open Authenticator board
* Functions to read the three tactile switches on Open Authenticator board
* Defines macros with pin numbers of connected peripherals

Documentation: https://open-authenticator.github.io/open-authenticator-component/
## Installation

```
cd <your_esp_idf_project>
mkdir components
cd components
git clone https://github.com/Open-Authenticator/open-authenticator-component.git
```

## Contributors

* [Vedant Paranjape](https://github.com/VedantParanjape)

## License

```
MIT License

Copyright (c) 2020 Vedant Paranjape

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```
