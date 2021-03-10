template<typename T>
struct Vector {
    private:
      int actual = -1;
      arx::vector<T> list {};

    public:
      T next(){
        if (!isLast()){
          actual++;
        }
        return list[actual];
      }

      bool isLast(){
        return list.size() == actual + 1;
      }
  
      void clear(){
        actual = -1;
        list.clear();
      }

      int size(){
        return list.size();
      }
  
      void insert(T value){
        actual = -1;
        list.push_back(value);
      }
      
      arx::vector<T> iterator(){
        return list;
      }
};
