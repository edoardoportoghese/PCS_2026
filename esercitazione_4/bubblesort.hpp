#include <vector>

template<typename T>
int bubblesort(std::vector<T>& vec)
{
	for (int i=0; i+1<vec.size();i++){
		for (int j=vec.size()-1; j>i;j--){
			if (vec[j]<vec[j-1]){
				T tmp= vec[j];
				vec[j]=vec[j-1];
				vec[j-1]=tmp;
			}
		}
	}
	return 0;
}