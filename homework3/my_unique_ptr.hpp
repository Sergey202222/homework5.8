#ifndef MY_UNIQUE_PTR_HPP
#define MY_UNIQUE_PTR_HPP

namespace my_unique_ptr
{
	template<class Ttype>
	class unique_ptr
	{
	public:
		unique_ptr(Ttype* ptr) : _ptr{ptr} {};
		
		unique_ptr(const unique_ptr &ptr) = delete;

		~unique_ptr()
		{
			delete _ptr;
		}

		Ttype operator*()
		{
			return *_ptr;
		}

		Ttype* release()
		{
			Ttype* oldptr = _ptr;
			_ptr = nullptr;
			return oldptr;
		}

		unique_ptr& operator=(const unique_ptr& ptr) = delete;
	private:
		Ttype* _ptr{nullptr};
	};
}

#endif