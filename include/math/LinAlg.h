#include<iostream>
#include<iterator>

namespace linalg{
	template <typename T> class Matrix{
		public:
			T get(int row, int col);
			void set(int row, int col);
		private:
			List<List<T>> rows;
	}

	template<typename T> T Matrix<T>::get(int row, int col){
		if(rows.size < row) return 0;

		List<T> cols = rows.get(row);
		if(cols.size < col) return 0;

		return cols.get(col);
	};

	template<typename T> void Matrix<T>::set(){
		if(rows.size < row) return 0;

		List<T> cols = rows.get(row);
		if(cols.size < col) return 0;

		cols.
	};

	template <typename T> class List{
		public:
			void push(T val);
			void queue(T val);
			bool insert(int pos, T val);
			bool del(int pos);
			void set(int pos);
			T get(int pos);
			T poll();
			int getSize();

			class Iterator{
				public:
					Iterator(Node* pos = nullptr) : ptr(pos){}

					T& operator*();
					const T& operator*() const;
					T* operator->() const{return ptr;}

					Iterator operator++(int){
						ptr = ptr->next;
					}

					friend bool operator==(const Iterator& ten, const Iterator& ren){
						return ten.ptr == ren.ptr;
					}
					friend bool operator!=(const Iterator& ten, const Iterator& ren){
						return ten.ptr != ren.ptr;
					}
				private:
					Node* ptr;
			};
			Iterator begin(){
				return Iterator(data);
			}
			Iterator end(){
				return Iterator(data + size);
			}
			Iterator begin() const{
				return Iterator(data);
			}
			Iterator end() const{
				return Iterator(data + size);
			}
		private:
			class Node{
				public:
					Node(T data, node prev, node next){
						this->data = data;
						this->prev = prev;
						this->next = next;
					};

					T getData(){
						return data;
					};
					void setData(T data){
						this->data = data;
					};
					Node getPrev(){
						return prev;
					};
					Node getNext(){
						return next;
					};
				private:
					T data;
					Node* prev;
					Node* next;
			}

			Node* head = nullptr;
			Node* tail = nullptr;

			int size = 0;
	}

	void List::push(T val){
		Node node(val, nullptr, head);
		head.prev = node;
		head = node;

		if(tail == nullptr) tail = node;
	};

	void List::queue(T val){
		Node node(val, tail, nullptr);
		tail.next = node;
		tail = node;

		if(head == nullptr) head = node;
	};

	bool List::insert(int pos, val){
		if(pos+1 > size){
			return false;
		}

		Node itr = first;
		for(int count = 0; count != pos; count++, 
		itr = itr.getNext());

		itr.prev.next = new Node(val, itr.prev, itr);
		itr.prev = itr.prev.next;

		return true;
	};

	bool List::del(int pos){
		if(pos+1 > size){
			return false;
		}

		Node itr = first;
		for(int count = 0; count != pos; count++, 
		itr = itr.getNext());

		itr.prev.next = itr.next;
		itr.next.prev = itr.prev;
		itr = nullptr;

		return true;
	};

	void List::set(int pos, T val){
		if(pos+1 > size){
			return false;
		}

		Node itr = first;
		for(int count = 0; count != pos; count++, 
		itr = itr.getNext());

		if(itr.getData() == val) return 0;
		itr.
	};

	template<typename T> T List<T>::get(int pos){
		if(pos+1 > size) throw std::out_of_range("called out of range");

		typename List<T>Node itr = first;
		for(int count = 0; count != pos; count++, 
		itr = itr.getNext());
		
		return itr.getData();
	};

	template<typename T> T List<T>::poll(){
		if(size < 1) throw std::out_of_range("polled from empty list");

		typename List<T>::Node node = head;
		if(tail == node) tail = node.prev;
		head = head.next;

		return node.getData();
	};

	int List::getSize(){ 
		return size;
	};
}
