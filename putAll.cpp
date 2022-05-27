#include<iostream>
#include<cstring>
#include<vector>
#include<unordered_map>

class MagicMap{
  private:
    std::vector<std::string> keys;
    std::vector<std::string> values;
    std::unordered_map<std::string,int> keyLut;
    std::unordered_map<std::string,int> valueLut;
    int count = 0;
  public:
    MagicMap(){
      keys = {};
      values = {};
    }
    std::string get(std::string key){ 
      if(keyLut.find(key) == keyLut.end()) throw "Key not found!";
      std::cout<<"get "<<key<<" value: "<<values[count]<<std::endl;
      return values[count];
    }
    void put(std::string key, std::string value){
      keyLut[key] = count;
      valueLut[value] = count;
      count++;
      keys.push_back(key);
      values.push_back(value);
      std::cout<<"put "<<key<<" "<<values[count]<<std::endl;
    }
    void putAll(std::string value){
      values.insert(values.begin(),keys.size(),value);
      for(int i= 0; i< keys.size(); i++)
      {
        std::cout<<"putAll key "<<keys[i]<<" value: "<<values[i]<<std::endl;
      }
    }
};

int main(){
  MagicMap mmap;
  //mmap.get("A");
  mmap.put("A","1");
  mmap.get("A");
  mmap.put("B","2");
  mmap.put("C","3");
  mmap.get("C");
  mmap.putAll("5");
  return 0;
}
