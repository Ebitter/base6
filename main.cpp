#include <iostream>
#include "base64.h"
#include "stdio.h"
int main(int argc, char *argv[])
{
    FILE *picFile, *base64File;
    if((picFile = fopen("./pic.jpg", "rb")) == NULL)
    {
        std::cout << "pic open error!" << std::endl;
        exit(0);
    }
    //计算文件大小
    fseek(picFile, 0 , SEEK_END);
    size_t picLen = ftell(picFile);
    std::cout << "pic len=" << picLen << std::endl;
    fseek(picFile, 0, SEEK_SET);

    unsigned char *picBuf = new unsigned char[picLen];
    fread(picBuf, picLen, 1, picFile);
    fclose(picFile);
    std::string encoded = base64_encode(picBuf, picLen);
    delete []picBuf;
    std::cout << "pic base64= " << encoded;

    //写文件
    if((base64File = fopen("./base64.txt", "wb")) == NULL)
    {
        std::cout << "base64.txt open error!" << std::endl;
        exit(0);
    }
    fwrite(encoded.c_str(), encoded.size(), 1, base64File);
    fclose(base64File);
    return 0;
}
