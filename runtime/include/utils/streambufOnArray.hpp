#ifndef _UTILS_STREAMBUFONARRAY_HPP_
#define _UTILS_STREAMBUFONARRAY_HPP_


#include <algorithm>
#include <cstring>
#include <stdexcept>
#include <streambuf>
#include <vector>
#include <boost/limits.hpp>
#include <boost/throw_exception.hpp>
#include <boost/asio/detail/noncopyable.hpp>

namespace utils
{

	class StreambufOnArray
		: public std::streambuf
		, private boost::noncopyable
	{
	public:
		typedef boost::shared_array<char> buffer_type;

		/// Construct a basic_streambuf object.
		/**
		* Constructs a streambuf with the specified maximum size. The initial size
		* of the streambuf's input sequence is 0.
		*/
		explicit StreambufOnArray()
			: _size(0)
		{
			std::size_t pend = buffer_delta;
			resize((std::max<std::size_t>)(pend, 1));
			setg(_buffer.get(), _buffer.get(), _buffer.get());
			setp(_buffer.get(), _buffer.get(), _buffer.get() + pend);
		}

		explicit StreambufOnArray(const buffer_type &buffer, std::size_t size)
			: _buffer(buffer)
			, _size(size)
		{
			std::size_t pend = size;
			setg(_buffer.get(), _buffer.get(), _buffer.get() + pend);
			setp(_buffer.get(), _buffer.get() + pend, _buffer.get() + pend);
		}

		std::size_t size() const
		{
			return pptr() - gptr();
		}

		buffer_type data() const
		{
			return _buffer;
		}


	protected:
		enum { buffer_delta = 128 };

		/// Override std::streambuf behaviour.
		/**
		* Behaves according to the specification of @c std::streambuf::underflow().
		*/
		int_type underflow()
		{
			if (gptr() < pptr())
			{
				setg(_buffer.get(), gptr(), pptr());
				return traits_type::to_int_type(*gptr());
			}
			else
			{
				return traits_type::eof();
			}
		}

		/// Override std::streambuf behaviour.
		/**
		* Behaves according to the specification of @c std::streambuf::overflow(),
		* with the specialisation that @c std::length_error is thrown if appending
		* the character to the input sequence would require the condition
		* <tt>size() > max_size()</tt> to be true.
		*/
		int_type overflow(int_type c)
		{
			if (!traits_type::eq_int_type(c, traits_type::eof()))
			{
				if (pptr() == epptr())
				{
					reserve(buffer_delta);
				}

				*pptr() = traits_type::to_char_type(c);
				pbump(1);
				return c;
			}

			return traits_type::not_eof(c);
		}

		void reserve(std::size_t n)
		{
			// Get current stream positions as offsets.
			std::size_t gnext = gptr() - _buffer.get();
			std::size_t pnext = pptr() - _buffer.get();
			std::size_t pend = epptr() - _buffer.get();

			// Check if there is already enough space in the put area.
			if (n <= pend - pnext)
			{
				return;
			}

			// Shift existing contents of get area to start of buffer.
			if (gnext > 0)
			{
				pnext -= gnext;
				std::memmove(_buffer.get(), _buffer.get() + gnext, pnext);
			}

			// Ensure buffer is large enough to hold at least the specified size.
			if (n > pend - pnext)
			{
				pend = pnext + n;
				resize((std::max<std::size_t>)(pend, 1));
			}

			// Update stream positions.
			setg(_buffer.get(), _buffer.get(), _buffer.get() + pnext);
			setp(_buffer.get() + pnext, _buffer.get() + pend);
		}

	private:
		buffer_type _buffer;
		std::size_t	_size;

		void resize(std::size_t newSize)
		{
			buffer_type newBuf(new char[newSize]);
			if(_buffer)
			{
				std::size_t moveSize = std::min(_size, newSize);
				std::memmove(newBuf.get(), _buffer.get(), moveSize);
			}

			_buffer.swap(newBuf);
			_size = newSize;
		}
	};
}


#endif
