#include <map>
#include <limits>

template<typename K, typename V>
class interval_map {
	std::map<K,V> m_map;

public:
    // constructor associates whole range of K with val by inserting (K_min, val)
    // into the map
    interval_map( V const& val) {
        m_map.insert(m_map.end(),std::make_pair(std::numeric_limits<K>::lowest(),val));
    }

    // Assign value val to interval [keyBegin, keyEnd).
    // Overwrite previous values in this interval.
    // Conforming to the C++ Standard Library conventions, the interval
    // includes keyBegin, but excludes keyEnd.
    // If !( keyBegin < keyEnd ), this designates an empty interval,
    // and assign must do nothing.
    void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
    //no floats allowed, will cause floating point arithmetic-related issues
 
    //when looping
    if (keyBegin%1 != 0 || keyEnd%1 != 0) return; 
    if (keyBegin >= keyEnd) return;

    //check if keyBegin/keyEnd are valid chars (a-z or A-Z only)
    bool begin_is_char = false;
    bool end_is_char = false;
    if (((keyBegin>='a' && keyBegin<='z')||(keyBegin>='A' && keyBegin<='Z')) && ((keyEnd>='a' && keyEnd<='z')||(keyEnd>='A' && keyEnd<='Z'))){
       begin_is_char = true;
       end_is_char = true;
    } 
    if(begin_is_char == true && end_is_char == true){
       for(char i= keyBegin; i< keyEnd; ++i)
          m_map.at(i) = val;
    }
    else{
       if (keyBegin >=0){//treat as unsigned if keyBegin is >=0
         for(unsigned int i= keyBegin; i< keyEnd; i++)
           m_map.at(i) = val;
       }
       else{//treat as signed if keyBegin is <0
         for(int i= keyBegin; i< keyEnd; i++)
           m_map.at(i) = val;
       }
    }

    }

    // look-up of the value associated with key
    V const& operator[]( K const& key ) const {
        return ( --m_map.upper_bound(key) )->second;
    }
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of unsigned int intervals to char.