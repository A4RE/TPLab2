#include "helper.h"

bool checkFilename(std::string file)
{
    if (file.size() < 4 && file[0] != '0') {
        std::cout << "Имя файла слишком короткое." << std::endl;
        return false;
    }

    int i = file.size();
    if ((file[i] == '\0') && (file[i - 1] == 't') && (file[i - 2] == 'x') && (file[i - 3] == 't') && (file[i - 4] == '.') ||
        (file[i] == '\0') && (file[i - 1] == 'c') && (file[i - 2] == 'o') && (file[i - 3] == 'd') && (file[i - 4] == '.'))
        return true;
    else
    {
        if (file[i - 1] != '0')
            std::cout << "Файл должен иметь формат .txt или .doc" << std::endl;
        return false;
    }
}

bool processInputNameOfInputFile(std::string& filename)
{
    std::ifstream file;
    bool isCorrect;
    std::cout << "Введите название файла (с расширением): ";
    std::cin >> filename;
    isCorrect = checkFilename(filename);
    if (isCorrect)
        file.open(filename);
    while (!file.is_open())
    {

        if (isCorrect)
            std::cout << "Такого файла не существует.\n";
        std::cout << "Введите название повторно (с расширением): ";
        std::cin >> filename;
        isCorrect = checkFilename(filename);
        if (isCorrect)
            file.open(filename);
    }
    file.close();
    std::cout << "Файл успешно открыт\n";
    return true;
}
