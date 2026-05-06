#include <optional>

template<typename T>
bool is_sorted(const std::vector<T>& vec)
{   
	if (vec.size() == 0) {
		return true; 
		}
	for (int i=0; i+1<vec.size();i++){
		if (vec[i]>vec[i+1]) {
			return false;
			}
		}
	return true;
}
		