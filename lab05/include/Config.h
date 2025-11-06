#ifndef CONFIG_H
#define CONFIG_H

const int MAX_CONFIGS = 10;
const int KEY_LEN = 20;
const int VALUE_LEN = 50;

class Config {
private:
    char keys[MAX_CONFIGS][KEY_LEN];
    char values[MAX_CONFIGS][VALUE_LEN];
    int size;

public:
    Config();
    bool add(const char* key, const char* value);
    const char* get(const char* key) const;
    bool remove(const char* key);
    void clear();
    int count() const;
    void print() const;

    inline bool isFull() const { return size >= MAX_CONFIGS; }
};

#endif
