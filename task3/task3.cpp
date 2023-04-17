#include <iostream>
#include <vector>

using namespace std;


template <typename K, typename V>
class AssociativeArray {
private:
	vector < pair < K, V>> list;

public:


	void put(K key, V value);

	void clear();

	V findByKey(K key);

	void removeByKey(K key);

	void print();

};


int main()
{
	AssociativeArray<int, int>* array = new AssociativeArray<int, int>();
	array->put(2, 4);
	array->put(4, 16);
	array->put(6, 64);
	array->print();
	cout<<array->findByKey(4);

}

template<typename K, typename V>
void AssociativeArray<K, V>::put(K key, V value) {
	V v = findByKey(key);
	if (v == NULL) {
		list.push_back(make_pair(key, value));
	}

}

template<typename K, typename V>
void AssociativeArray<K, V>::clear() {
	list.clear();
}

template<typename K, typename V>
V AssociativeArray<K, V>::findByKey(K key) {
	for (auto& p : list) {
		if (p.first == key) {
			return p.second;
		}
	}
	return NULL;
}

template<typename K, typename V>
void AssociativeArray<K, V>::removeByKey(K key) {
	for (auto it = list.begin(); it != list.end(); it++) {
		if (it->first == key) {
			list.erase(it);
			break;
		}
	}
}

template<typename K, typename V>
void AssociativeArray<K, V>::print() {
	for (const auto& pair : list) {
		cout<<"key = "<< pair.first<< ", value = "<< pair.second<<endl;

	}
}