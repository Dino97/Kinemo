#pragma once

#include <string>
#include <iostream>

class FileUtilities
{
public:
	static std::string ReadFile(const char* path)
	{
		FILE* file = fopen(path, "rt");

		if (file == NULL)
		{
			std::cout << "FileUtilities_ReadFileError: File cannot be found. ( " << path << ")" << std::endl;
			return NULL;
		}

		fseek(file, 0, SEEK_END);
		unsigned long length = ftell(file);
		char* data = new char[length + 1];
		memset(data, 0, length + 1);
		fseek(file, 0, SEEK_SET);
		fread(data, 1, length, file);
		fclose(file);

		std::string result(data);
		delete[] data;
		return result;
	}
};