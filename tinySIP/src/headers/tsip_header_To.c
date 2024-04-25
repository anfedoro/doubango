
/* #line 1 "./ragel/tsip_parser_header_To.rl" */
/*
* Copyright (C) 2010-2011 Mamadou Diop.
*
* Contact: Mamadou Diop <diopmamadou(at)doubango[dot]org>
*
* This file is part of Open Source Doubango Framework.
*
* DOUBANGO is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* DOUBANGO is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with DOUBANGO.
*
*/

/**@file tsip_header_To.c
 * @brief SIP To/t header.
 *
 * @author Mamadou Diop <diopmamadou(at)doubango[dot]org>
 *

 */
#include "tinysip/headers/tsip_header_To.h"

#include "tinysip/parsers/tsip_parser_uri.h"

#include "tsk_debug.h"
#include "tsk_memory.h"



/***********************************
*   Ragel state machine.
*/

/* #line 89 "./ragel/tsip_parser_header_To.rl" */


tsip_header_To_t* tsip_header_To_create(const char* display_name, const tsip_uri_t* uri, const char* tag)
{
    return tsk_object_new(TSIP_HEADER_TO_VA_ARGS(display_name, uri, tag));
}

tsip_header_To_t* tsip_header_To_create_null()
{
    return tsip_header_To_create(tsk_null, tsk_null, tsk_null);
}

int tsip_header_To_serialize(const tsip_header_t* header, tsk_buffer_t* output)
{
    if(header) {
        int ret = 0;
        const tsip_header_To_t *To = (const tsip_header_To_t *)header;

        /* Uri with hacked display-name*/
        if((ret = tsip_uri_serialize(To->uri, tsk_true, tsk_true, output))) {
            return ret;
        }
        if(To->tag && (ret = tsk_buffer_append_2(output, ";tag=%s", To->tag))) {
            return ret;
        }
        return ret;
    }
    return -1;
}

tsip_header_To_t *tsip_header_To_parse(const char *data, tsk_size_t size)
{
    int cs = 0;
    const char *p = data;
    const char *pe = p + size;
    const char *eof = pe;
    tsip_header_To_t *hdr_to = tsip_header_To_create_null();

    const char *tag_start = tsk_null;


    /* #line 88 "./src/headers/tsip_header_To.c" */
    static const char _tsip_machine_parser_header_To_actions[] = {
        0, 1, 0, 1, 1, 1, 2, 1,
        3, 1, 4, 1, 5, 2, 1, 3,
        2, 1, 4
    };

    static const short _tsip_machine_parser_header_To_key_offsets[] = {
        0, 0, 2, 7, 10, 31, 32, 34,
        55, 56, 58, 61, 65, 77, 80, 80,
        81, 85, 86, 105, 106, 108, 126, 145,
        150, 151, 153, 157, 176, 177, 179, 198,
        199, 201, 204, 212, 213, 215, 219, 223,
        224, 226, 229, 235, 253, 260, 268, 276,
        284, 286, 293, 302, 304, 307, 309, 312,
        314, 317, 320, 321, 324, 325, 328, 329,
        338, 347, 355, 363, 371, 379, 381, 387,
        396, 405, 414, 416, 419, 422, 423, 424,
        445, 466, 485, 490, 491, 493, 497, 516,
        517, 519, 538, 556, 573, 591, 595, 596,
        598, 606, 607, 609, 613, 619, 639, 658,
        663, 663, 667, 687, 706, 711, 731, 749,
        758, 762, 787, 811, 821, 845, 868, 876,
        885, 901, 918, 935, 952, 963, 979, 997,
        1008, 1020, 1031, 1043, 1054, 1066, 1078, 1088,
        1100, 1110, 1122, 1132, 1150, 1168, 1185, 1202,
        1219, 1236, 1247, 1262, 1280, 1298, 1316, 1327,
        1339, 1351, 1361, 1371, 1397, 1423, 1447, 1457,
        1481, 1504, 1515, 1527, 1539, 1551, 1557, 1568,
        1581, 1587, 1594, 1600, 1607, 1613, 1620, 1627,
        1632, 1639, 1644, 1651, 1656, 1669, 1682, 1694,
        1706, 1718, 1730, 1736, 1746, 1759, 1772, 1785,
        1791, 1798, 1805, 1810, 1815, 1836, 1857, 1876,
        1881, 1901, 1919
    };

    static const char _tsip_machine_parser_header_To_trans_keys[] = {
        84, 116, 9, 32, 58, 79, 111, 9,
        32, 58, 9, 13, 32, 33, 34, 37,
        39, 60, 126, 42, 43, 45, 46, 48,
        57, 65, 90, 95, 96, 97, 122, 10,
        9, 32, 9, 13, 32, 33, 34, 37,
        39, 60, 126, 42, 43, 45, 46, 48,
        57, 65, 90, 95, 96, 97, 122, 10,
        9, 32, 9, 32, 60, 65, 90, 97,
        122, 9, 32, 43, 58, 45, 46, 48,
        57, 65, 90, 97, 122, 9, 32, 58,
        62, 9, 13, 32, 59, 10, 9, 13,
        32, 33, 37, 39, 84, 116, 126, 42,
        43, 45, 46, 48, 57, 65, 90, 95,
        122, 10, 9, 32, 9, 32, 33, 37,
        39, 84, 116, 126, 42, 43, 45, 46,
        48, 57, 65, 90, 95, 122, 9, 13,
        32, 33, 37, 39, 59, 61, 126, 42,
        43, 45, 46, 48, 57, 65, 90, 95,
        122, 9, 13, 32, 59, 61, 10, 9,
        32, 9, 32, 59, 61, 9, 13, 32,
        33, 34, 37, 39, 91, 126, 42, 43,
        45, 46, 48, 57, 65, 90, 95, 122,
        10, 9, 32, 9, 13, 32, 33, 34,
        37, 39, 91, 126, 42, 43, 45, 46,
        48, 57, 65, 90, 95, 122, 10, 9,
        32, 9, 32, 34, 13, 34, 92, 127,
        0, 8, 10, 31, 10, 9, 32, 9,
        13, 32, 59, 9, 13, 32, 59, 10,
        9, 32, 9, 32, 59, 0, 9, 11,
        12, 14, 127, 9, 13, 32, 33, 37,
        39, 59, 126, 42, 43, 45, 46, 48,
        57, 65, 90, 95, 122, 58, 48, 57,
        65, 70, 97, 102, 58, 93, 48, 57,
        65, 70, 97, 102, 58, 93, 48, 57,
        65, 70, 97, 102, 58, 93, 48, 57,
        65, 70, 97, 102, 58, 93, 58, 48,
        57, 65, 70, 97, 102, 46, 58, 93,
        48, 57, 65, 70, 97, 102, 48, 57,
        46, 48, 57, 48, 57, 46, 48, 57,
        48, 57, 93, 48, 57, 93, 48, 57,
        93, 46, 48, 57, 46, 46, 48, 57,
        46, 46, 58, 93, 48, 57, 65, 70,
        97, 102, 46, 58, 93, 48, 57, 65,
        70, 97, 102, 58, 93, 48, 57, 65,
        70, 97, 102, 58, 93, 48, 57, 65,
        70, 97, 102, 58, 93, 48, 57, 65,
        70, 97, 102, 58, 93, 48, 57, 65,
        70, 97, 102, 58, 93, 48, 57, 65,
        70, 97, 102, 46, 58, 93, 48, 57,
        65, 70, 97, 102, 46, 58, 93, 48,
        57, 65, 70, 97, 102, 46, 58, 93,
        48, 57, 65, 70, 97, 102, 48, 57,
        46, 48, 57, 46, 48, 57, 46, 58,
        9, 13, 32, 33, 37, 39, 59, 61,
        65, 97, 126, 42, 43, 45, 46, 48,
        57, 66, 90, 95, 122, 9, 13, 32,
        33, 37, 39, 59, 61, 71, 103, 126,
        42, 43, 45, 46, 48, 57, 65, 90,
        95, 122, 9, 13, 32, 33, 37, 39,
        59, 61, 126, 42, 43, 45, 46, 48,
        57, 65, 90, 95, 122, 9, 13, 32,
        59, 61, 10, 9, 32, 9, 32, 59,
        61, 9, 13, 32, 33, 34, 37, 39,
        91, 126, 42, 43, 45, 46, 48, 57,
        65, 90, 95, 122, 10, 9, 32, 9,
        13, 32, 33, 34, 37, 39, 91, 126,
        42, 43, 45, 46, 48, 57, 65, 90,
        95, 122, 9, 13, 32, 33, 37, 39,
        59, 126, 42, 43, 45, 46, 48, 57,
        65, 90, 95, 122, 9, 13, 32, 33,
        37, 39, 126, 42, 43, 45, 46, 48,
        57, 65, 90, 95, 122, 9, 13, 32,
        33, 37, 39, 60, 126, 42, 43, 45,
        46, 48, 57, 65, 90, 95, 122, 9,
        13, 32, 60, 10, 9, 32, 13, 34,
        92, 127, 0, 8, 10, 31, 10, 9,
        32, 9, 13, 32, 60, 0, 9, 11,
        12, 14, 127, 9, 13, 32, 33, 37,
        39, 42, 43, 58, 126, 45, 46, 48,
        57, 65, 90, 95, 96, 97, 122, 9,
        13, 32, 33, 37, 39, 58, 60, 126,
        42, 43, 45, 46, 48, 57, 65, 90,
        95, 122, 9, 13, 32, 58, 60, 9,
        13, 32, 59, 9, 13, 32, 33, 37,
        39, 59, 84, 116, 126, 42, 43, 45,
        46, 48, 57, 65, 90, 95, 122, 9,
        13, 32, 33, 37, 39, 59, 61, 126,
        42, 43, 45, 46, 48, 57, 65, 90,
        95, 122, 9, 13, 32, 59, 61, 9,
        13, 32, 33, 34, 37, 39, 59, 91,
        126, 42, 43, 45, 46, 48, 57, 65,
        90, 95, 122, 9, 13, 32, 33, 37,
        39, 59, 126, 42, 43, 45, 46, 48,
        57, 65, 90, 95, 122, 9, 13, 32,
        34, 59, 92, 127, 0, 31, 9, 13,
        32, 59, 9, 13, 32, 33, 34, 37,
        39, 59, 84, 92, 116, 126, 127, 0,
        31, 42, 43, 45, 46, 48, 57, 65,
        90, 95, 122, 9, 13, 32, 33, 34,
        37, 39, 59, 61, 92, 126, 127, 0,
        31, 42, 43, 45, 46, 48, 57, 65,
        90, 95, 122, 9, 13, 32, 34, 59,
        61, 92, 127, 0, 31, 9, 13, 32,
        33, 34, 37, 39, 59, 91, 92, 126,
        127, 0, 31, 42, 43, 45, 46, 48,
        57, 65, 90, 95, 122, 9, 13, 32,
        33, 34, 37, 39, 59, 92, 126, 127,
        0, 31, 42, 43, 45, 46, 48, 57,
        65, 90, 95, 122, 9, 13, 32, 59,
        0, 8, 11, 127, 9, 13, 32, 34,
        59, 92, 127, 0, 31, 9, 13, 32,
        34, 58, 59, 92, 127, 0, 31, 48,
        57, 65, 70, 97, 102, 9, 13, 32,
        34, 58, 59, 92, 93, 127, 0, 31,
        48, 57, 65, 70, 97, 102, 9, 13,
        32, 34, 58, 59, 92, 93, 127, 0,
        31, 48, 57, 65, 70, 97, 102, 9,
        13, 32, 34, 58, 59, 92, 93, 127,
        0, 31, 48, 57, 65, 70, 97, 102,
        9, 13, 32, 34, 58, 59, 92, 93,
        127, 0, 31, 9, 13, 32, 34, 58,
        59, 92, 127, 0, 31, 48, 57, 65,
        70, 97, 102, 9, 13, 32, 34, 46,
        58, 59, 92, 93, 127, 0, 31, 48,
        57, 65, 70, 97, 102, 9, 13, 32,
        34, 59, 92, 127, 0, 31, 48, 57,
        9, 13, 32, 34, 46, 59, 92, 127,
        0, 31, 48, 57, 9, 13, 32, 34,
        59, 92, 127, 0, 31, 48, 57, 9,
        13, 32, 34, 46, 59, 92, 127, 0,
        31, 48, 57, 9, 13, 32, 34, 59,
        92, 127, 0, 31, 48, 57, 9, 13,
        32, 34, 59, 92, 93, 127, 0, 31,
        48, 57, 9, 13, 32, 34, 59, 92,
        93, 127, 0, 31, 48, 57, 9, 13,
        32, 34, 59, 92, 93, 127, 0, 31,
        9, 13, 32, 34, 46, 59, 92, 127,
        0, 31, 48, 57, 9, 13, 32, 34,
        46, 59, 92, 127, 0, 31, 9, 13,
        32, 34, 46, 59, 92, 127, 0, 31,
        48, 57, 9, 13, 32, 34, 46, 59,
        92, 127, 0, 31, 9, 13, 32, 34,
        46, 58, 59, 92, 93, 127, 0, 31,
        48, 57, 65, 70, 97, 102, 9, 13,
        32, 34, 46, 58, 59, 92, 93, 127,
        0, 31, 48, 57, 65, 70, 97, 102,
        9, 13, 32, 34, 58, 59, 92, 93,
        127, 0, 31, 48, 57, 65, 70, 97,
        102, 9, 13, 32, 34, 58, 59, 92,
        93, 127, 0, 31, 48, 57, 65, 70,
        97, 102, 9, 13, 32, 34, 58, 59,
        92, 93, 127, 0, 31, 48, 57, 65,
        70, 97, 102, 9, 13, 32, 34, 58,
        59, 92, 93, 127, 0, 31, 48, 57,
        65, 70, 97, 102, 9, 13, 32, 34,
        58, 59, 92, 93, 127, 0, 31, 9,
        13, 32, 34, 59, 92, 127, 0, 31,
        48, 57, 65, 70, 97, 102, 9, 13,
        32, 34, 46, 58, 59, 92, 93, 127,
        0, 31, 48, 57, 65, 70, 97, 102,
        9, 13, 32, 34, 46, 58, 59, 92,
        93, 127, 0, 31, 48, 57, 65, 70,
        97, 102, 9, 13, 32, 34, 46, 58,
        59, 92, 93, 127, 0, 31, 48, 57,
        65, 70, 97, 102, 9, 13, 32, 34,
        59, 92, 127, 0, 31, 48, 57, 9,
        13, 32, 34, 46, 59, 92, 127, 0,
        31, 48, 57, 9, 13, 32, 34, 46,
        59, 92, 127, 0, 31, 48, 57, 9,
        13, 32, 34, 46, 59, 92, 127, 0,
        31, 9, 13, 32, 34, 58, 59, 92,
        127, 0, 31, 9, 13, 32, 33, 34,
        37, 39, 59, 61, 65, 92, 97, 126,
        127, 0, 31, 42, 43, 45, 46, 48,
        57, 66, 90, 95, 122, 9, 13, 32,
        33, 34, 37, 39, 59, 61, 71, 92,
        103, 126, 127, 0, 31, 42, 43, 45,
        46, 48, 57, 65, 90, 95, 122, 9,
        13, 32, 33, 34, 37, 39, 59, 61,
        92, 126, 127, 0, 31, 42, 43, 45,
        46, 48, 57, 65, 90, 95, 122, 9,
        13, 32, 34, 59, 61, 92, 127, 0,
        31, 9, 13, 32, 33, 34, 37, 39,
        59, 91, 92, 126, 127, 0, 31, 42,
        43, 45, 46, 48, 57, 65, 90, 95,
        122, 9, 13, 32, 33, 34, 37, 39,
        59, 92, 126, 127, 0, 31, 42, 43,
        45, 46, 48, 57, 65, 90, 95, 122,
        9, 13, 32, 58, 59, 48, 57, 65,
        70, 97, 102, 9, 13, 32, 58, 59,
        93, 48, 57, 65, 70, 97, 102, 9,
        13, 32, 58, 59, 93, 48, 57, 65,
        70, 97, 102, 9, 13, 32, 58, 59,
        93, 48, 57, 65, 70, 97, 102, 9,
        13, 32, 58, 59, 93, 9, 13, 32,
        58, 59, 48, 57, 65, 70, 97, 102,
        9, 13, 32, 46, 58, 59, 93, 48,
        57, 65, 70, 97, 102, 9, 13, 32,
        59, 48, 57, 9, 13, 32, 46, 59,
        48, 57, 9, 13, 32, 59, 48, 57,
        9, 13, 32, 46, 59, 48, 57, 9,
        13, 32, 59, 48, 57, 9, 13, 32,
        59, 93, 48, 57, 9, 13, 32, 59,
        93, 48, 57, 9, 13, 32, 59, 93,
        9, 13, 32, 46, 59, 48, 57, 9,
        13, 32, 46, 59, 9, 13, 32, 46,
        59, 48, 57, 9, 13, 32, 46, 59,
        9, 13, 32, 46, 58, 59, 93, 48,
        57, 65, 70, 97, 102, 9, 13, 32,
        46, 58, 59, 93, 48, 57, 65, 70,
        97, 102, 9, 13, 32, 58, 59, 93,
        48, 57, 65, 70, 97, 102, 9, 13,
        32, 58, 59, 93, 48, 57, 65, 70,
        97, 102, 9, 13, 32, 58, 59, 93,
        48, 57, 65, 70, 97, 102, 9, 13,
        32, 58, 59, 93, 48, 57, 65, 70,
        97, 102, 9, 13, 32, 58, 59, 93,
        9, 13, 32, 59, 48, 57, 65, 70,
        97, 102, 9, 13, 32, 46, 58, 59,
        93, 48, 57, 65, 70, 97, 102, 9,
        13, 32, 46, 58, 59, 93, 48, 57,
        65, 70, 97, 102, 9, 13, 32, 46,
        58, 59, 93, 48, 57, 65, 70, 97,
        102, 9, 13, 32, 59, 48, 57, 9,
        13, 32, 46, 59, 48, 57, 9, 13,
        32, 46, 59, 48, 57, 9, 13, 32,
        46, 59, 9, 13, 32, 58, 59, 9,
        13, 32, 33, 37, 39, 59, 61, 65,
        97, 126, 42, 43, 45, 46, 48, 57,
        66, 90, 95, 122, 9, 13, 32, 33,
        37, 39, 59, 61, 71, 103, 126, 42,
        43, 45, 46, 48, 57, 65, 90, 95,
        122, 9, 13, 32, 33, 37, 39, 59,
        61, 126, 42, 43, 45, 46, 48, 57,
        65, 90, 95, 122, 9, 13, 32, 59,
        61, 9, 13, 32, 33, 34, 37, 39,
        59, 91, 126, 42, 43, 45, 46, 48,
        57, 65, 90, 95, 122, 9, 13, 32,
        33, 37, 39, 59, 126, 42, 43, 45,
        46, 48, 57, 65, 90, 95, 122, 0
    };

    static const char _tsip_machine_parser_header_To_single_lengths[] = {
        0, 2, 5, 3, 9, 1, 2, 9,
        1, 2, 3, 0, 4, 3, 0, 1,
        4, 1, 9, 1, 2, 8, 9, 5,
        1, 2, 4, 9, 1, 2, 9, 1,
        2, 3, 4, 1, 2, 4, 4, 1,
        2, 3, 0, 8, 1, 2, 2, 2,
        2, 1, 3, 0, 1, 0, 1, 0,
        1, 1, 1, 1, 1, 1, 1, 3,
        3, 2, 2, 2, 2, 2, 0, 3,
        3, 3, 0, 1, 1, 1, 1, 11,
        11, 9, 5, 1, 2, 4, 9, 1,
        2, 9, 8, 7, 8, 4, 1, 2,
        4, 1, 2, 4, 0, 10, 9, 5,
        0, 4, 10, 9, 5, 10, 8, 7,
        4, 13, 12, 8, 12, 11, 4, 7,
        8, 9, 9, 9, 9, 8, 10, 7,
        8, 7, 8, 7, 8, 8, 8, 8,
        8, 8, 8, 10, 10, 9, 9, 9,
        9, 9, 7, 10, 10, 10, 7, 8,
        8, 8, 8, 14, 14, 12, 8, 12,
        11, 5, 6, 6, 6, 6, 5, 7,
        4, 5, 4, 5, 4, 5, 5, 5,
        5, 5, 5, 5, 7, 7, 6, 6,
        6, 6, 6, 4, 7, 7, 7, 4,
        5, 5, 5, 5, 11, 11, 9, 5,
        10, 8, 0
    };

    static const char _tsip_machine_parser_header_To_range_lengths[] = {
        0, 0, 0, 0, 6, 0, 0, 6,
        0, 0, 0, 2, 4, 0, 0, 0,
        0, 0, 5, 0, 0, 5, 5, 0,
        0, 0, 0, 5, 0, 0, 5, 0,
        0, 0, 2, 0, 0, 0, 0, 0,
        0, 0, 3, 5, 3, 3, 3, 3,
        0, 3, 3, 1, 1, 1, 1, 1,
        1, 1, 0, 1, 0, 1, 0, 3,
        3, 3, 3, 3, 3, 0, 3, 3,
        3, 3, 1, 1, 1, 0, 0, 5,
        5, 5, 0, 0, 0, 0, 5, 0,
        0, 5, 5, 5, 5, 0, 0, 0,
        2, 0, 0, 0, 3, 5, 5, 0,
        0, 0, 5, 5, 0, 5, 5, 1,
        0, 6, 6, 1, 6, 6, 2, 1,
        4, 4, 4, 4, 1, 4, 4, 2,
        2, 2, 2, 2, 2, 2, 1, 2,
        1, 2, 1, 4, 4, 4, 4, 4,
        4, 1, 4, 4, 4, 4, 2, 2,
        2, 1, 1, 6, 6, 6, 1, 6,
        6, 3, 3, 3, 3, 0, 3, 3,
        1, 1, 1, 1, 1, 1, 1, 0,
        1, 0, 1, 0, 3, 3, 3, 3,
        3, 3, 0, 3, 3, 3, 3, 1,
        1, 1, 0, 0, 5, 5, 5, 0,
        5, 5, 0
    };

    static const short _tsip_machine_parser_header_To_index_offsets[] = {
        0, 0, 3, 9, 13, 29, 31, 34,
        50, 52, 55, 59, 62, 71, 75, 76,
        78, 83, 85, 100, 102, 105, 119, 134,
        140, 142, 145, 150, 165, 167, 170, 185,
        187, 190, 194, 201, 203, 206, 211, 216,
        218, 221, 225, 229, 243, 248, 254, 260,
        266, 269, 274, 281, 283, 286, 288, 291,
        293, 296, 299, 301, 304, 306, 309, 311,
        318, 325, 331, 337, 343, 349, 352, 356,
        363, 370, 377, 379, 382, 385, 387, 389,
        406, 423, 438, 444, 446, 449, 454, 469,
        471, 474, 489, 503, 516, 530, 535, 537,
        540, 547, 549, 552, 557, 561, 577, 592,
        598, 599, 604, 620, 635, 641, 657, 671,
        680, 685, 705, 724, 734, 753, 771, 778,
        787, 800, 814, 828, 842, 853, 866, 881,
        891, 902, 912, 923, 933, 944, 955, 965,
        976, 986, 997, 1007, 1022, 1037, 1051, 1065,
        1079, 1093, 1104, 1116, 1131, 1146, 1161, 1171,
        1182, 1193, 1203, 1213, 1234, 1255, 1274, 1284,
        1303, 1321, 1330, 1340, 1350, 1360, 1367, 1376,
        1387, 1393, 1400, 1406, 1413, 1419, 1426, 1433,
        1439, 1446, 1452, 1459, 1465, 1476, 1487, 1497,
        1507, 1517, 1527, 1534, 1542, 1553, 1564, 1575,
        1581, 1588, 1595, 1601, 1607, 1624, 1641, 1656,
        1662, 1678, 1692
    };

    static const unsigned char _tsip_machine_parser_header_To_indicies[] = {
        0, 0, 1, 2, 2, 3, 2, 2,
        1, 2, 2, 3, 1, 3, 4, 3,
        5, 6, 5, 5, 7, 5, 5, 5,
        5, 8, 5, 8, 1, 9, 1, 10,
        10, 1, 10, 11, 10, 5, 6, 5,
        5, 7, 5, 5, 5, 5, 8, 5,
        8, 1, 12, 1, 13, 13, 1, 13,
        13, 7, 1, 14, 14, 1, 15, 15,
        16, 17, 16, 16, 16, 16, 1, 15,
        15, 17, 1, 18, 19, 18, 20, 21,
        20, 22, 1, 23, 1, 22, 24, 22,
        25, 25, 25, 26, 26, 25, 25, 25,
        25, 25, 25, 1, 27, 1, 28, 28,
        1, 28, 28, 25, 25, 25, 26, 26,
        25, 25, 25, 25, 25, 25, 1, 29,
        30, 29, 31, 31, 31, 32, 33, 31,
        31, 31, 31, 31, 31, 1, 34, 35,
        34, 22, 33, 1, 36, 1, 37, 37,
        1, 37, 37, 22, 33, 1, 33, 38,
        33, 39, 40, 39, 39, 41, 39, 39,
        39, 39, 39, 39, 1, 42, 1, 43,
        43, 1, 43, 44, 43, 39, 40, 39,
        39, 41, 39, 39, 39, 39, 39, 39,
        1, 45, 1, 46, 46, 1, 46, 46,
        40, 1, 47, 48, 49, 1, 1, 1,
        40, 50, 1, 40, 40, 1, 51, 30,
        51, 32, 1, 52, 53, 52, 22, 1,
        54, 1, 55, 55, 1, 55, 55, 22,
        1, 40, 40, 40, 1, 51, 30, 51,
        39, 39, 39, 32, 39, 39, 39, 39,
        39, 39, 1, 57, 56, 56, 56, 1,
        59, 48, 58, 58, 58, 1, 59, 48,
        60, 60, 60, 1, 59, 48, 61, 61,
        61, 1, 59, 48, 1, 63, 62, 56,
        56, 1, 64, 59, 48, 65, 58, 58,
        1, 66, 1, 67, 68, 1, 69, 1,
        70, 71, 1, 72, 1, 48, 73, 1,
        48, 74, 1, 48, 1, 70, 75, 1,
        70, 1, 67, 76, 1, 67, 1, 64,
        59, 48, 77, 60, 60, 1, 64, 59,
        48, 61, 61, 61, 1, 79, 48, 78,
        78, 78, 1, 81, 48, 80, 80, 80,
        1, 81, 48, 82, 82, 82, 1, 81,
        48, 83, 83, 83, 1, 81, 48, 1,
        84, 78, 78, 1, 64, 81, 48, 85,
        80, 80, 1, 64, 81, 48, 86, 82,
        82, 1, 64, 81, 48, 83, 83, 83,
        1, 87, 1, 64, 88, 1, 64, 89,
        1, 64, 1, 63, 1, 29, 30, 29,
        31, 31, 31, 32, 33, 90, 90, 31,
        31, 31, 31, 31, 31, 1, 29, 30,
        29, 31, 31, 31, 32, 33, 91, 91,
        31, 31, 31, 31, 31, 31, 1, 92,
        30, 92, 31, 31, 31, 32, 93, 31,
        31, 31, 31, 31, 31, 1, 94, 95,
        94, 22, 93, 1, 96, 1, 97, 97,
        1, 97, 97, 22, 93, 1, 93, 98,
        93, 99, 40, 99, 99, 41, 99, 99,
        99, 99, 99, 99, 1, 100, 1, 101,
        101, 1, 101, 44, 101, 99, 40, 99,
        99, 41, 99, 99, 99, 99, 99, 99,
        1, 102, 103, 102, 104, 104, 104, 105,
        104, 104, 104, 104, 104, 104, 1, 106,
        107, 106, 108, 108, 108, 108, 108, 108,
        108, 108, 108, 1, 109, 110, 109, 108,
        108, 108, 111, 108, 108, 108, 108, 108,
        108, 1, 112, 11, 112, 7, 1, 113,
        1, 106, 106, 1, 115, 116, 117, 1,
        1, 1, 114, 118, 1, 114, 114, 1,
        109, 110, 109, 111, 1, 114, 114, 114,
        1, 119, 107, 119, 108, 108, 108, 108,
        120, 121, 108, 120, 120, 120, 108, 120,
        1, 122, 110, 122, 108, 108, 108, 121,
        111, 108, 108, 108, 108, 108, 108, 1,
        123, 11, 123, 121, 7, 1, 124, 125,
        126, 125, 127, 124, 127, 126, 127, 128,
        128, 128, 127, 129, 129, 128, 128, 128,
        128, 128, 128, 124, 130, 131, 130, 132,
        132, 132, 133, 134, 132, 132, 132, 132,
        132, 132, 124, 135, 126, 135, 127, 134,
        124, 136, 126, 136, 137, 138, 137, 137,
        127, 139, 137, 137, 137, 137, 137, 137,
        124, 140, 131, 140, 137, 137, 137, 133,
        137, 137, 137, 137, 137, 137, 124, 141,
        126, 141, 142, 143, 144, 124, 124, 138,
        140, 131, 140, 133, 124, 143, 126, 143,
        145, 142, 145, 145, 143, 146, 144, 146,
        145, 124, 124, 145, 145, 145, 145, 145,
        138, 147, 131, 147, 148, 142, 148, 148,
        149, 150, 144, 148, 124, 124, 148, 148,
        148, 148, 148, 138, 151, 126, 151, 142,
        143, 150, 144, 124, 124, 138, 152, 126,
        152, 153, 154, 153, 153, 143, 155, 144,
        153, 124, 124, 153, 153, 153, 153, 153,
        138, 156, 131, 156, 153, 142, 153, 153,
        149, 144, 153, 124, 124, 153, 153, 153,
        153, 153, 138, 141, 126, 141, 143, 138,
        138, 124, 156, 131, 156, 142, 149, 144,
        124, 124, 138, 141, 126, 141, 142, 158,
        143, 144, 124, 124, 157, 157, 157, 138,
        141, 126, 141, 142, 160, 143, 144, 154,
        124, 124, 159, 159, 159, 138, 141, 126,
        141, 142, 160, 143, 144, 154, 124, 124,
        161, 161, 161, 138, 141, 126, 141, 142,
        160, 143, 144, 154, 124, 124, 162, 162,
        162, 138, 141, 126, 141, 142, 160, 143,
        144, 154, 124, 124, 138, 141, 126, 141,
        142, 164, 143, 144, 124, 124, 163, 157,
        157, 138, 141, 126, 141, 142, 165, 160,
        143, 144, 154, 124, 124, 166, 159, 159,
        138, 141, 126, 141, 142, 143, 144, 124,
        124, 167, 138, 141, 126, 141, 142, 168,
        143, 144, 124, 124, 169, 138, 141, 126,
        141, 142, 143, 144, 124, 124, 170, 138,
        141, 126, 141, 142, 171, 143, 144, 124,
        124, 172, 138, 141, 126, 141, 142, 143,
        144, 124, 124, 173, 138, 141, 126, 141,
        142, 143, 144, 154, 124, 124, 174, 138,
        141, 126, 141, 142, 143, 144, 154, 124,
        124, 175, 138, 141, 126, 141, 142, 143,
        144, 154, 124, 124, 138, 141, 126, 141,
        142, 171, 143, 144, 124, 124, 176, 138,
        141, 126, 141, 142, 171, 143, 144, 124,
        124, 138, 141, 126, 141, 142, 168, 143,
        144, 124, 124, 177, 138, 141, 126, 141,
        142, 168, 143, 144, 124, 124, 138, 141,
        126, 141, 142, 165, 160, 143, 144, 154,
        124, 124, 178, 161, 161, 138, 141, 126,
        141, 142, 165, 160, 143, 144, 154, 124,
        124, 162, 162, 162, 138, 141, 126, 141,
        142, 180, 143, 144, 154, 124, 124, 179,
        179, 179, 138, 141, 126, 141, 142, 182,
        143, 144, 154, 124, 124, 181, 181, 181,
        138, 141, 126, 141, 142, 182, 143, 144,
        154, 124, 124, 183, 183, 183, 138, 141,
        126, 141, 142, 182, 143, 144, 154, 124,
        124, 184, 184, 184, 138, 141, 126, 141,
        142, 182, 143, 144, 154, 124, 124, 138,
        141, 126, 141, 142, 143, 144, 124, 124,
        185, 179, 179, 138, 141, 126, 141, 142,
        165, 182, 143, 144, 154, 124, 124, 186,
        181, 181, 138, 141, 126, 141, 142, 165,
        182, 143, 144, 154, 124, 124, 187, 183,
        183, 138, 141, 126, 141, 142, 165, 182,
        143, 144, 154, 124, 124, 184, 184, 184,
        138, 141, 126, 141, 142, 143, 144, 124,
        124, 188, 138, 141, 126, 141, 142, 165,
        143, 144, 124, 124, 189, 138, 141, 126,
        141, 142, 165, 143, 144, 124, 124, 190,
        138, 141, 126, 141, 142, 165, 143, 144,
        124, 124, 138, 141, 126, 141, 142, 164,
        143, 144, 124, 124, 138, 147, 131, 147,
        148, 142, 148, 148, 149, 150, 191, 144,
        191, 148, 124, 124, 148, 148, 148, 148,
        148, 138, 147, 131, 147, 148, 142, 148,
        148, 149, 150, 192, 144, 192, 148, 124,
        124, 148, 148, 148, 148, 148, 138, 193,
        131, 193, 148, 142, 148, 148, 149, 194,
        144, 148, 124, 124, 148, 148, 148, 148,
        148, 138, 195, 126, 195, 142, 143, 194,
        144, 124, 124, 138, 196, 126, 196, 197,
        154, 197, 197, 143, 155, 144, 197, 124,
        124, 197, 197, 197, 197, 197, 138, 198,
        199, 198, 200, 142, 200, 200, 201, 144,
        200, 124, 124, 200, 200, 200, 200, 200,
        138, 125, 126, 125, 203, 127, 202, 202,
        202, 124, 125, 126, 125, 205, 127, 142,
        204, 204, 204, 124, 125, 126, 125, 205,
        127, 142, 206, 206, 206, 124, 125, 126,
        125, 205, 127, 142, 207, 207, 207, 124,
        125, 126, 125, 205, 127, 142, 124, 125,
        126, 125, 209, 127, 208, 202, 202, 124,
        125, 126, 125, 210, 205, 127, 142, 211,
        204, 204, 124, 125, 126, 125, 127, 212,
        124, 125, 126, 125, 213, 127, 214, 124,
        125, 126, 125, 127, 215, 124, 125, 126,
        125, 216, 127, 217, 124, 125, 126, 125,
        127, 218, 124, 125, 126, 125, 127, 142,
        219, 124, 125, 126, 125, 127, 142, 220,
        124, 125, 126, 125, 127, 142, 124, 125,
        126, 125, 216, 127, 221, 124, 125, 126,
        125, 216, 127, 124, 125, 126, 125, 213,
        127, 222, 124, 125, 126, 125, 213, 127,
        124, 125, 126, 125, 210, 205, 127, 142,
        223, 206, 206, 124, 125, 126, 125, 210,
        205, 127, 142, 207, 207, 207, 124, 125,
        126, 125, 225, 127, 142, 224, 224, 224,
        124, 125, 126, 125, 227, 127, 142, 226,
        226, 226, 124, 125, 126, 125, 227, 127,
        142, 228, 228, 228, 124, 125, 126, 125,
        227, 127, 142, 229, 229, 229, 124, 125,
        126, 125, 227, 127, 142, 124, 125, 126,
        125, 127, 230, 224, 224, 124, 125, 126,
        125, 210, 227, 127, 142, 231, 226, 226,
        124, 125, 126, 125, 210, 227, 127, 142,
        232, 228, 228, 124, 125, 126, 125, 210,
        227, 127, 142, 229, 229, 229, 124, 125,
        126, 125, 127, 233, 124, 125, 126, 125,
        210, 127, 234, 124, 125, 126, 125, 210,
        127, 235, 124, 125, 126, 125, 210, 127,
        124, 125, 126, 125, 209, 127, 124, 130,
        131, 130, 132, 132, 132, 133, 134, 236,
        236, 132, 132, 132, 132, 132, 132, 124,
        130, 131, 130, 132, 132, 132, 133, 134,
        237, 237, 132, 132, 132, 132, 132, 132,
        124, 238, 131, 238, 132, 132, 132, 133,
        239, 132, 132, 132, 132, 132, 132, 124,
        240, 126, 240, 127, 239, 124, 241, 126,
        241, 242, 138, 242, 242, 127, 139, 242,
        242, 242, 242, 242, 242, 124, 243, 199,
        243, 244, 244, 244, 245, 244, 244, 244,
        244, 244, 244, 124, 1, 0
    };

    static const unsigned char _tsip_machine_parser_header_To_trans_targs[] = {
        2, 0, 3, 4, 5, 91, 96, 11,
        101, 6, 7, 8, 9, 10, 12, 13,
        12, 14, 15, 16, 16, 17, 18, 202,
        19, 22, 79, 20, 21, 23, 17, 22,
        18, 27, 23, 24, 25, 26, 28, 43,
        34, 44, 29, 30, 31, 32, 33, 35,
        37, 42, 36, 38, 38, 39, 40, 41,
        45, 78, 46, 49, 47, 48, 50, 65,
        51, 63, 52, 53, 61, 54, 55, 59,
        56, 57, 58, 60, 62, 64, 66, 74,
        67, 70, 68, 69, 71, 72, 73, 75,
        76, 77, 80, 81, 82, 86, 82, 83,
        84, 85, 87, 90, 88, 89, 38, 17,
        90, 18, 92, 94, 91, 93, 8, 11,
        93, 95, 96, 97, 99, 100, 98, 102,
        101, 104, 103, 103, 105, 105, 17, 106,
        107, 196, 108, 17, 107, 106, 109, 108,
        109, 110, 111, 161, 105, 111, 112, 113,
        118, 114, 155, 115, 114, 113, 116, 115,
        116, 117, 119, 120, 111, 121, 154, 122,
        125, 123, 124, 126, 141, 127, 139, 128,
        129, 137, 130, 131, 135, 132, 133, 134,
        136, 138, 140, 142, 150, 143, 146, 144,
        145, 147, 148, 149, 151, 152, 153, 156,
        157, 158, 159, 158, 159, 160, 111, 17,
        160, 113, 162, 195, 163, 166, 164, 165,
        167, 182, 168, 180, 169, 170, 178, 171,
        172, 176, 173, 174, 175, 177, 179, 181,
        183, 191, 184, 187, 185, 186, 188, 189,
        190, 192, 193, 194, 197, 198, 199, 200,
        199, 200, 201, 105, 201, 106
    };

    static const char _tsip_machine_parser_header_To_trans_actions[] = {
        0, 0, 0, 0, 0, 1, 1, 0,
        1, 0, 0, 0, 0, 0, 1, 0,
        0, 0, 0, 3, 0, 0, 0, 11,
        0, 1, 1, 0, 0, 9, 9, 0,
        9, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 9, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 9, 0, 0, 0,
        0, 0, 0, 1, 0, 0, 7, 7,
        0, 7, 0, 0, 0, 5, 5, 5,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 5, 0, 0, 3, 3, 3,
        1, 1, 16, 16, 0, 16, 0, 3,
        3, 0, 0, 0, 16, 3, 0, 3,
        0, 1, 1, 16, 0, 16, 0, 3,
        3, 0, 0, 0, 16, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 16, 0, 3, 3, 1, 13, 13,
        0, 13, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 16, 0,
        3, 3, 1, 13, 0, 13
    };

    static const int tsip_machine_parser_header_To_start = 1;
    static const int tsip_machine_parser_header_To_first_final = 202;
    static const int tsip_machine_parser_header_To_error = 0;

    static const int tsip_machine_parser_header_To_en_main = 1;


    /* #line 130 "./ragel/tsip_parser_header_To.rl" */
    (void)(eof);
    (void)(tsip_machine_parser_header_To_first_final);
    (void)(tsip_machine_parser_header_To_error);
    (void)(tsip_machine_parser_header_To_en_main);

    /* #line 750 "./src/headers/tsip_header_To.c" */
    {
        cs = tsip_machine_parser_header_To_start;
    }

    /* #line 135 "./ragel/tsip_parser_header_To.rl" */

    /* #line 757 "./src/headers/tsip_header_To.c" */
    {
        int _klen;
        unsigned int _trans;
        const char *_acts;
        unsigned int _nacts;
        const char *_keys;

        if ( p == pe ) {
            goto _test_eof;
        }
        if ( cs == 0 ) {
            goto _out;
        }
_resume:
        _keys = _tsip_machine_parser_header_To_trans_keys + _tsip_machine_parser_header_To_key_offsets[cs];
        _trans = _tsip_machine_parser_header_To_index_offsets[cs];

        _klen = _tsip_machine_parser_header_To_single_lengths[cs];
        if ( _klen > 0 ) {
            const char *_lower = _keys;
            const char *_mid;
            const char *_upper = _keys + _klen - 1;
            while (1) {
                if ( _upper < _lower ) {
                    break;
                }

                _mid = _lower + ((_upper-_lower) >> 1);
                if ( (*p) < *_mid ) {
                    _upper = _mid - 1;
                }
                else if ( (*p) > *_mid ) {
                    _lower = _mid + 1;
                }
                else {
                    _trans += (_mid - _keys);
                    goto _match;
                }
            }
            _keys += _klen;
            _trans += _klen;
        }

        _klen = _tsip_machine_parser_header_To_range_lengths[cs];
        if ( _klen > 0 ) {
            const char *_lower = _keys;
            const char *_mid;
            const char *_upper = _keys + (_klen<<1) - 2;
            while (1) {
                if ( _upper < _lower ) {
                    break;
                }

                _mid = _lower + (((_upper-_lower) >> 1) & ~1);
                if ( (*p) < _mid[0] ) {
                    _upper = _mid - 2;
                }
                else if ( (*p) > _mid[1] ) {
                    _lower = _mid + 2;
                }
                else {
                    _trans += ((_mid - _keys)>>1);
                    goto _match;
                }
            }
            _trans += _klen;
        }

_match:
        _trans = _tsip_machine_parser_header_To_indicies[_trans];
        cs = _tsip_machine_parser_header_To_trans_targs[_trans];

        if ( _tsip_machine_parser_header_To_trans_actions[_trans] == 0 ) {
            goto _again;
        }

        _acts = _tsip_machine_parser_header_To_actions + _tsip_machine_parser_header_To_trans_actions[_trans];
        _nacts = (unsigned int) *_acts++;
        while ( _nacts-- > 0 ) {
            switch ( *_acts++ ) {
            case 0:
                /* #line 48 "./ragel/tsip_parser_header_To.rl" */
            {
                tag_start = p;
            }
            break;
            case 1:
                /* #line 52 "./ragel/tsip_parser_header_To.rl" */
            {
                int len = (int)(p  - tag_start);
                if(hdr_to && !hdr_to->uri) {
                    if((hdr_to->uri = tsip_uri_parse(tag_start, (tsk_size_t)len)) && hdr_to->display_name) {
                        hdr_to->uri->display_name = tsk_strdup(hdr_to->display_name);
                    }
                }
            }
            break;
            case 2:
                /* #line 61 "./ragel/tsip_parser_header_To.rl" */
            {
                TSK_PARSER_SET_STRING(hdr_to->display_name);
                tsk_strunquote(&hdr_to->display_name);
            }
            break;
            case 3:
                /* #line 66 "./ragel/tsip_parser_header_To.rl" */
            {
                TSK_PARSER_SET_STRING(hdr_to->tag);
            }
            break;
            case 4:
                /* #line 70 "./ragel/tsip_parser_header_To.rl" */
            {
                TSK_PARSER_ADD_PARAM(TSIP_HEADER_PARAMS(hdr_to));
            }
            break;
            case 5:
                /* #line 74 "./ragel/tsip_parser_header_To.rl" */
            {
            }
            break;
                /* #line 872 "./src/headers/tsip_header_To.c" */
            }
        }

_again:
        if ( cs == 0 ) {
            goto _out;
        }
        if ( ++p != pe ) {
            goto _resume;
        }
_test_eof: {
        }
_out: {
        }
    }

    /* #line 136 "./ragel/tsip_parser_header_To.rl" */

    if( cs <
            /* #line 888 "./src/headers/tsip_header_To.c" */
            202
            /* #line 137 "./ragel/tsip_parser_header_To.rl" */
      ) {
        TSK_DEBUG_ERROR("Failed to parse 'To' header.");
        TSK_OBJECT_SAFE_FREE(hdr_to);
    }

    return hdr_to;
}







//========================================================
//  To header object definition
//

static tsk_object_t* tsip_header_To_ctor(tsk_object_t *self, va_list * app)
{
    tsip_header_To_t *To = self;
    if(To) {
        const char* display_name = va_arg(*app, const char *);
        const tsip_uri_t* uri = va_arg(*app, const tsip_uri_t *);
        const char* tag = va_arg(*app, const char *);

        To->display_name = tsk_strdup(display_name);
        if(uri) {
            To->uri = tsk_object_ref((void *)uri);
        }
        To->tag = tsk_strdup(tag);

        TSIP_HEADER(To)->type = tsip_htype_To;
        TSIP_HEADER(To)->serialize = tsip_header_To_serialize;
    }
    else {
        TSK_DEBUG_ERROR("Failed to create new To header.");
    }
    return self;
}

static tsk_object_t* tsip_header_To_dtor(tsk_object_t *self)
{
    tsip_header_To_t *To = self;
    if(To) {
        TSK_FREE(To->display_name);
        TSK_FREE(To->tag);

        TSK_OBJECT_SAFE_FREE(To->uri);
        TSK_OBJECT_SAFE_FREE(TSIP_HEADER_PARAMS(To));
    }
    else {
        TSK_DEBUG_ERROR("Null To header.");
    }

    return self;
}

static const tsk_object_def_t tsip_header_To_def_s = {
    sizeof(tsip_header_To_t),
    tsip_header_To_ctor,
    tsip_header_To_dtor,
    tsk_null
};
const tsk_object_def_t *tsip_header_To_def_t = &tsip_header_To_def_s;
