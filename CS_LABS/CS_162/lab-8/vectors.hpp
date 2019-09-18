#include <stdlib.h>
template <class T>
class vector {
   private:
      T *v;
      int s;
   public:
      vector(){
	     s=0;
	     v=NULL;
      }

      ~vector(){
	     delete [] v;
      }

      int size() {
	     return s;
      }
	  T getindex(int i){
		  return v[i];
	  }
      void push_back(T ele) {
	     T *temp;
	     temp = new T[++s];
	     for(int i=0; i<s-1; i++)
	        temp[i]=v[i];

	     delete [] v;
	     v=temp;
	     v[s-1]=ele;
      }
	  vector(vector<T> &O){
		  for(int i = 0; i < O.s; i++){
			  v[i] = O.v[i];
		  }

	  }
	  void operator=(vector<T> &O){
		  if(v != NULL){
			 delete[]v;
		  if(s != 0){
		  	v = new T[O.s];
			for(int i = 0; i < O.s; i++){
				v[i] = O.v[i];
			}

			s = O.s;
		   }

	  	   }
  		}

	T operator[](int i){
		
	}
};
