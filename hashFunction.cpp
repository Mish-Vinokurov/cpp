int hashFunction(float number, int tableSize) {
  unsigned char *byteArray = (unsigned char*)&number;
  int sum = 0;

  for (int = 0; i < sizeof(float); i++) {
    sum += byteArray[i];
  }

  return sum % tableSize;
}

//Свойства:
//Функция не требует дополнительной памяти
//для одного и того же числа всегда будет один и тот же хэш-код
//хэш-коды распределены равномерно по всему диапазону значений

