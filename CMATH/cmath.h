typedef unsigned char bool;
#define false 0
#define true 1

/**
 * Değişken sayıda argüman alabilen bir makro tanımıdır.
 * Bu makro, verilen türde bir dizi oluşturur ve bu dizinin boyutunu hesaplar.
 * Makro, verilen türdeki elemanların sayısını geri döndürür.
 *
 * @param type Makro tarafından kullanılan tür.
 * @param ...  Değişken sayıda argüman. Makro, bu argümanları bir diziye ekler ve dizinin boyutunu hesaplar.
 * @return Verilen türdeki elemanların sayısını döndürür.
 */
#define NUMARGS(type, ...) (sizeof((type[]){0.0f, ##__VA_ARGS__}) / sizeof(type) - 1)
