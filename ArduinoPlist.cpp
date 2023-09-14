#include "Arduino.h"
#include "ArduinoPlist.h"

ArduinoPlist::ArduinoPlist(String path) {
  this->filePath = path;
  this->plistData = "";
}

bool ArduinoPlist::create() {
  if (SD.exists(this->filePath)) {
    return false;
  }
  this->plistFile = SD.open(this->filePath, FILE_WRITE);
  if (this->plistFile) {
    this->plistFile.close();
    return true;
  }
  return false;
}

bool ArduinoPlist::write(String data) {
  this->plistFile = SD.open(this->filePath, FILE_WRITE);
  if (this->plistFile) {
    this->plistFile.println(data);
    this->plistFile.close();
    return true;
  }
  return false;
}

bool ArduinoPlist::deletePlist() {
  if (SD.exists(this->filePath)) {
    SD.remove(this->filePath);
    return true;
  }
  return false;
}

bool ArduinoPlist::isValid() {
  this->plistFile = SD.open(this->filePath);
  if (this->plistFile) {
    // Add your logic here to check the validity of the plist file.
    // This could involve checking the file format, structure, etc.
    this->plistFile.close();
    return true;
  }
  return false;
}

String ArduinoPlist::parse() {
  String data = "";
  this->plistFile = SD.open(this->filePath);
  if (this->plistFile) {
    while (this->plistFile.available()) {
      data += (char)this->plistFile.read();
    }
    this->plistFile.close();
  }
  // Add your logic here to parse the plist file and extract the data you need.
  return data;
}

String ArduinoPlist::find(String key) {
  String data = this->parse();
  // Add your logic here to find and return the data associated with the given key.
  return data;
}

bool ArduinoPlist::removeKey(String key) {
  // Add your logic here to remove the key from your data structure
  // For example, if you're using a dictionary or map, you might do something like this:
  // this->plistData.erase(key);
  
  // Then write the modified data structure back to the plist file
  return this->write(this->plistData);
}

bool ArduinoPlist::checkKey(String key) {
  // Add your logic here to check if the key exists in your data structure
  // For example, if you're using a dictionary or map, you might do something like this:
  // return this->plistData.count(key) > 0;

  // For simplicity, I'll just return false here
  return false;
}
