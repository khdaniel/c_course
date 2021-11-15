#ifndef CONVERT_H
#define CONVERT_H

typedef enum {WRONG_ENCODING=-100, CP1251=0, KOI8, ISO8859} encoding;
typedef unsigned char uchar;

typedef struct {
    char *lvl;
    int lsz;   
} letter;

static const long CP1251ToUTF[256] = {
	0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,
	31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,
	59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,
	87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,
	111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,1026,1027,8218,
	1107,8222,8230,8224,8225,8364,8240,1033,8249,1034,1036,1035,1039,1106,8216,8217,
	8220,8221,8226,8211,8212,8250,8482,1113,8250,1114,1116,1115,1119,160,1038,1118,1032,
	164,1168,166,167,1025,169,1028,171,172,173,174,1031,176,177,1030,1110,1169,181,182,
	183,1105,8470,1108,187,1112,1029,1109,1111,1040,1041,1042,1043,1044,1045,1046,1047,
	1048,1049,1050,1051,1052,1053,1054,1055,1056,1057,1058,1059,1060,1061,1062,1063,
	1064,1065,1066,1067,1068,1069,1070,1071,1072,1073,1074,1075,1076,1077,1078,1079,
	1080,1081,1082,1083,1084,1085,1086,1087,1088,1089,1090,1091,1092,1093,1094,1095,
	1096,1097,1098,1099,1100,1101,1102,1103
};

static const long ISO88595ToUTF[256] = {        
	0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,
	31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,
	61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,
	91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,
    116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,
    139,140,141,142,143,144,145,145,147,148,149,150,151,152,153,154,155,156,157,158,159,160,
	1025,1026,1027,1028,1029,1030,1031,1032,1033,1034,1035,1036,173,1038,1039,1040,
    1041,1042,1043,1044,1045,1046,1047,1048,1049,1050,1051,1052,1053,1054,1055,1056,
    1057,1058,1059,1060,1061,1062,1063,1064,1065,1066,1067,1068,1069,1070,1071,1072,
    1073,1074,1075,1076,1077,1078,1079,1080,1081,1082,1083,1084,1085,1086,1087,1088,
    1089,1090,1091,1092,1093,1094,1095,1096,1097,1098,1099,1100,1101,1102,1103,8470,
    1105,1106,1107,1108,1109,1110,1111,1112,1113,1114,1115,1116,1117,1118,1119
};

static const long KOI8ToUTF[256] = {
    0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,
	31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,
	59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,
	87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,
	111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,
    0x2500,0x2502,0x250C,0x2510,0x2514,0x2518,0x251C,0x2524,0x252C,0x2534,0x253C,0x2580,0x2584,
    0x2588,0x258C,0x2590,0x2591,0x2592,0x2593,0x2320,0x25A0,0x2219,0x221A,0x2248,0x2264,0x2265,
    0xA0,0x2321,0xB0,0xB2,0xB7,0xF7,0x2550,0x2551,0x2552,0x451,0x2553,0x2554,0x2555,0x2556,0x2557,
    0x2558,0x2559,0x255A,0x255B,0x255C,0x255D,0x255E,0x255F,0x2560,0x2561,0x401,0x2562,0x2563,
    0x2564,0x2565,0x2566,0x2567,0x2568,0x2569,0x256A,0x256B,0x256C,0xA9,0x44E,0x430,0x431,0x446,
    0x434,0x435,0x444,0x433,0x445,0x438,0x439,0x43A,0x43B,0x43C,0x43D,0x43E,0x43F,0x44F,0x440,
    0x441,0x442,0x443,0x436,0x432,0x44C,0x44B,0x437,0x448,0x44D,0x449,0x447,0x44A,0x42E,0x410,
    0x411,0x426,0x414,0x415,0x424,0x413,0x425,0x418,0x419,0x41A,0x41B,0x41C,0x41D,0x41E,0x41F,
    0x42F,0x420,0x421,0x422,0x423,0x416,0x412,0x42C,0x42B,0x417,0x428,0x42D,0x429,0x427,0x42A
};

void convertFileEncoding(const long[], char *sourceFilePath, char *destFilePath);

#endif
