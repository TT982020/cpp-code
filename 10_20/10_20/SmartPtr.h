#pragma once

//namespace name {
//	template<class T>
//	class auto_ptr {
//	public:
//		auto_ptr(T* ptr)
//			:_ptr(ptr) {
//			cout << "auto_ptr(T* ptr)" << endl;
//		}
//		auto_ptr(auto_ptr<T>& ap)
//			:_ptr(ap._ptr)
//		{
//			ap._ptr = nullptr;
//			cout << "auto_ptr(auto_ptr<T>& ap)" << endl;
//		}
//
//		~auto_ptr() {
//			cout << "~auto_ptr()" << endl;
//			delete _ptr;
//		}
//
//		T& operator*() {
//			return *_ptr;
//		}
//
//		T* operator->() {
//			return _ptr;
//		}
//	private:
//		T* _ptr;
//	};
//}


namespace name {
	template<class T>
	class unique_ptr
	{
	public:
		unique_ptr(T* ptr)
			:_ptr(ptr)
		{}

		~unique_ptr() {
			delete _ptr;
		}

		unique_ptr(unique_ptr<T>& up) = delete;
		unique_ptr<T>& operator=(unique_ptr<T>& up) = delete;


		T& operator*() {
			return *_ptr;
		}

		T* operator->() {
			return _ptr;
		}

	private:
		T* _ptr;

	};


	template<class T>
	class shared_ptr {
	public:
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, _pcount(new int(1)) {

		}

		shared_ptr(const shared_ptr& sp)
			:_ptr(sp._ptr)
			, _pcount(sp._pcount) {
			++(*_pcount);
		}

		~shared_ptr() {
			if (--(*_pcount) == 0)
			{
				cout << "delete " << _ptr << endl;
				delete _ptr;
				delete _pcount;
			}
		}

		shared_ptr<T>& operator=(const shared_ptr<T>& sp) {
			//如果同一个资源的指针进行赋值  还有是 自己给自己赋值 
			if (_ptr == sp._ptr)
			{
				return *this;
			}

			if (--(*_pcount) == 0) {
				delete _ptr;
				delete _pcount;
			}
			_ptr = sp._ptr;
			_pcount = sp._pcount;
			++(*_pcount);
			return *this;
		}

		T& operator*() {
			return *_ptr;
		}

		T* operator->() {
			return _ptr;
		}

		int use_count() const {
			return *_pcount;
		}

		T* get() const {
			return _ptr;
		}

	private:
		T* _ptr;
		int* _pcount;
	};

	template<class T>
	class weak_ptr {
	public:
		weak_ptr()
			:_ptr(nullptr)
		{}

		weak_ptr(const shared_ptr<T>& sp)
			:_ptr(sp.get())
		{}

		weak_ptr<T>& operator=(const shared_ptr<T>& sp) {
			_ptr = sp.get();
			return *this;
		}

		T& operator*() {
			return *_ptr;
		}

		T* operator->() {
			return _ptr;
		}
	private:
		T* _ptr;
	};
}
