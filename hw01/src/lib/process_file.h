#ifndef PROCESS_FILE
#define PROCESS_FILE

#include <stdbool.h>
#include <inttypes.h>

#pragma pack(push, 1)

typedef struct {
    char *filePath;    
} rawFile;

typedef struct {
    rawFile** files;
    int fileCount;
} processing;

typedef struct {
    uint32_t address;
    uint32_t centralDirectoryOffset;
} EOCDData;


typedef struct {
    uint32_t signature;
    uint16_t diskNumber;
    uint16_t startDiskNumber;
    uint16_t numberCentralDirectoryRecord;
    uint16_t totalCentralDirectoryRecord;
    uint32_t sizeOfCentralDirectory;
    uint32_t centralDirectoryOffset;
    uint16_t commentLength;
} EOCD;

typedef struct {   
    uint16_t versionMadeBy; 
    uint16_t versionToExtract;    
    uint16_t generalPurposeBitFlag;    
    uint16_t compressionMethod;    
    uint16_t modificationTime;
    uint16_t modificationDate;    
    uint32_t crc32;
    uint32_t compressedSize;
    uint32_t uncompressedSize;
    uint16_t filenameLength;
    uint16_t extraFieldLength;
    uint16_t fileCommentLength;
    uint16_t diskNumber;
    uint16_t internalFileAttributes;
    uint32_t externalFileAttributes;    
    uint32_t localFileHeaderOffset;    
    //uint8_t *filename; 
    //uint8_t *extraField;
    //uint8_t *fileComment;
} CDFH;

bool isFileZipArchive(rawFile*);
bool fileExists(rawFile*);

void enrichFilesDetails(rawFile*);

int processFiles(processing*);

void printFileNames(FILE*, EOCDData*);
void printFileName(CDFH*, FILE*);

void showDetails(char *);

#pragma pack(pop)
#endif
