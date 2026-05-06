#include <vector>

template<typename T>
int selection_sort(std::vector<T>& vec)
{
	for (int i=0; i+1<vec.size();i++){
		int ind_min=i;
		for (int j=i+1; j<vec.size();j++){
			if (vec[j]<vec[ind_min]){
				ind_min=j;
			}
		}
		T tmp= vec[i];
		vec[i]=vec[ind_min];
		vec[ind_min]=tmp;
	}
	return 0;
}