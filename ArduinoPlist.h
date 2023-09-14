#ifndef ArduinoPlist_h
#define ArduinoPlist_h

#include "Arduino.h"
#include "SD.h"

class ArduinoPlist {
  public:
    ArduinoPlist(String path);
    bool create();
    bool write(String data);
    bool deletePlist();
    bool isValid();
    String parse();
    String find(String key);
    bool removeKey(String key);
    bool checkKey(String key);
  private:
    File plistFile;
    String filePath;
    String plistData;
};

#endif
