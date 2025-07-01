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

		Ttype& operator*()
		{
			if (_ptr != nullptr)
			{
				return *_ptr;
			}
		}

		Ttype* operator->() const
		{
			return _ptr;
		}

		Ttype* release()
		{
			if (_ptr != nullptr)
			{
				Ttype* oldptr = _ptr;
				_ptr = nullptr;
				return oldptr;
			}
		}

		unique_ptr& operator=(const unique_ptr& ptr) = delete;
	private:
		Ttype* _ptr{nullptr};
	};
}

#endif