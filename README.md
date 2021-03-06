# charcnt_srt

## Overview
Count the number of characters in text file

## Description
Reads a text file, counts the number of alphanumeric characters (az, AZ, 0-9) in the file and outputs it to the standard output.

## Demo
![result](https://media.giphy.com/media/xUA7aNmZ75IuKx3L2g/giphy.gif)

## Install
Requires GNU make and gcc
```bash
$ git clone http://github.com/johejo/charcnt_srt.git
$ cd charcnt_srt
$ make
```

## Usage
Usage: ./charcnt_srt [-a] [-d] [-h] [-v] [FILE_NAME]

There are some option in this program.

If you do not specify an option, display results in ASCII code order.

-g      Display all characters. This is debug option.

-a      Display results in ascending order.

-d      Display results in descending order.

-h      Display this help.

-v      Display version.


```
$ ./charcnt_srt [-a] [-d] [-h] [-v] [FILE_NAME]
```

## License
This software is released under the MIT License, see LICENSE.
