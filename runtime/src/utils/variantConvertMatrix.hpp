#ifndef _UTILS_IMPL_VARIANTCONVERTMATRIX_HPP_
#define _UTILS_IMPL_VARIANTCONVERTMATRIX_HPP_

namespace utils
{
	namespace impl
	{
		namespace convertor
		{
			//////////////////////////////////////////////////////////////////////////
			//default
			template <class Dst, class Src>
			bool exec(Dst &dst, const Src &src)
			{
				return false;
			}
		}

		//////////////////////////////////////////////////////////////////////////
		template <class Dst, class Src>
		bool variantConvertMatrix(Dst &dst, const Src &src)
		{
			return convertor::exec(dst, src);
		}
	}
}





//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
namespace utils
{
	namespace impl
	{
		namespace convertor
		{

			//////////////////////////////////////////////////////////////////////////
			//identity
			template <class T>
			bool exec<>(T &dst, const T &src)
			{
				dst = src;
				return true;
			}

			//warning C4244: '=' : conversion from 'const utils::Variant::UInt16' to 'utils::Variant::UInt8', possible loss of data
#pragma warning (disable: 4244)

			//////////////////////////////////////////////////////////////////////////
			//integer to integer
			//unsigned <- unsigned
			//unsigned <- signed
			//signed <- unsigned
			//signed <- signed
			//real to real
			//integer to real
			//real to integer
#define ASSIGN(DST, SRC)	template <>	bool exec<>(Variant::DST &dst, const Variant::SRC &src){dst = src;return true;}

#define MASSIGN(SRC)\
	ASSIGN(Char, SRC)\
	ASSIGN(Int8, SRC)\
	ASSIGN(Int16, SRC)\
	ASSIGN(Int32, SRC)\
	ASSIGN(Int64, SRC)\
	ASSIGN(UInt8, SRC)\
	ASSIGN(UInt16, SRC)\
	ASSIGN(UInt32, SRC)\
	ASSIGN(UInt64, SRC)\
	ASSIGN(Float, SRC)\
	ASSIGN(Double, SRC)\

			MASSIGN(Char)
			MASSIGN(Int8)
			MASSIGN(Int16)
			MASSIGN(Int32)
			MASSIGN(Int64)
			MASSIGN(UInt8)
			MASSIGN(UInt16)
			MASSIGN(UInt32)
			MASSIGN(UInt64)
			MASSIGN(Float)
			MASSIGN(Double)

			//container to integer - size
			//container to real - size
#define CONTAINERSIZE(DST, SRC)	template <>	bool exec<>(Variant::DST &dst, const Variant::SRC &src){dst = src.size();return true;}
#define MCONTAINERSIZE(SRC)\
	CONTAINERSIZE(Char, SRC)\
	CONTAINERSIZE(Int8, SRC)\
	CONTAINERSIZE(Int16, SRC)\
	CONTAINERSIZE(Int32, SRC)\
	CONTAINERSIZE(Int64, SRC)\
	CONTAINERSIZE(UInt8, SRC)\
	CONTAINERSIZE(UInt16, SRC)\
	CONTAINERSIZE(UInt32, SRC)\
	CONTAINERSIZE(UInt64, SRC)\
	CONTAINERSIZE(Float, SRC)\
	CONTAINERSIZE(Double, SRC)\

			MCONTAINERSIZE(VectorChar)
			MCONTAINERSIZE(VectorVariant)
			MCONTAINERSIZE(MapStringVariant)
			MCONTAINERSIZE(MapVariantVariant)
			MCONTAINERSIZE(MultimapStringVariant)
			MCONTAINERSIZE(MultimapVariantVariant)
			MCONTAINERSIZE(SetVariant)
			MCONTAINERSIZE(MultisetVariant)
			MCONTAINERSIZE(DequeVariant)
			MCONTAINERSIZE(ListVariant)

















			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
			struct BitsetHelper
			{
				//////////////////////////////////////////////////////////////////////////
				//bs < bs
				//////////////////////////////////////////////////////////////////////////
				template <size_t NDst, size_t NSrc>
				static 
					typename boost::enable_if_c<
						(NDst == NSrc)
						, bool>::type 
					bs2bs(std::bitset<NDst> &dst, const std::bitset<NSrc> &src)
				{
					dst = src;
					return true;
				}

				//////////////////////////////////////////////////////////////////////////
				template <size_t NDst, size_t NSrc>
				static 
					typename boost::enable_if_c<
						(NDst < NSrc)
						, bool>::type 
					bs2bs(std::bitset<NDst> &dst, const std::bitset<NSrc> &src)
				{
					for(size_t i(0); i<NDst; i++)
					{
						dst.set(i, src.test(i));
					}
					return true;
				}
				//////////////////////////////////////////////////////////////////////////
				template <size_t NDst, size_t NSrc>
				static 
					typename boost::enable_if_c<
						(NDst > NSrc)
						, bool>::type 
					bs2bs(std::bitset<NDst> &dst, const std::bitset<NSrc> &src)
				{
					dst.reset();
					for(size_t i(0); i<NSrc; i++)
					{
						dst.set(i, src.test(i));
					}
					return true;
				}

				//////////////////////////////////////////////////////////////////////////
				//int < bs
				//////////////////////////////////////////////////////////////////////////
				template <class Int, size_t NSrc>
				static bool bs2int(Int &dst, const std::bitset<NSrc> &src)
				{
					dst = 0;
					for(size_t i(0); i<std::min(sizeof(Int)*sizeof(char), NSrc); i++)
					{
						if(src.test(i))
						{
							dst |= Int(1)<<i;
						}
					}
					return true;
				}

				//////////////////////////////////////////////////////////////////////////
				//bs < int
				//////////////////////////////////////////////////////////////////////////
				template <size_t NDst, class Int>
				static bool int2bs(std::bitset<NDst> &dst, const Int &src)
				{
					dst.reset();
					for(size_t i(0); i<std::min(NDst, sizeof(Int)*sizeof(char)); i++)
					{
						dst.set(i, src & (Int(1)<<i));
					}
					return true;
				}
			};
			

			//bitset to bitset
#define BITSET2BITSET(DST, SRC)	template <>	bool exec<>(Variant::DST &dst, const Variant::SRC &src){return BitsetHelper::bs2bs(dst, src);}

#define MBITSET2BITSET(SRC)\
	BITSET2BITSET(Bitset8, SRC)\
	BITSET2BITSET(Bitset16, SRC)\
	BITSET2BITSET(Bitset32, SRC)\
	BITSET2BITSET(Bitset64, SRC)\
	BITSET2BITSET(Bitset128, SRC)\
	BITSET2BITSET(Bitset256, SRC)\
	BITSET2BITSET(Bitset512, SRC)\

			MBITSET2BITSET(Bitset8)
			MBITSET2BITSET(Bitset16)
			MBITSET2BITSET(Bitset32)
			MBITSET2BITSET(Bitset64)
			MBITSET2BITSET(Bitset128)
			MBITSET2BITSET(Bitset256)
			MBITSET2BITSET(Bitset512)

			//bitset to integer
			//integer to bitset
#define BITSET2INT(DST, SRC)\
	template <>	bool exec<>(Variant::DST &dst, const Variant::SRC &src){return BitsetHelper::bs2int(dst, src);}\
	template <>	bool exec<>(Variant::SRC &dst, const Variant::DST &src){return BitsetHelper::int2bs(dst, src);}\


#define MBITSET2INT(DST)\
	BITSET2INT(DST, Bitset8)\
	BITSET2INT(DST, Bitset16)\
	BITSET2INT(DST, Bitset32)\
	BITSET2INT(DST, Bitset64)\
	BITSET2INT(DST, Bitset128)\
	BITSET2INT(DST, Bitset256)\
	BITSET2INT(DST, Bitset512)\

			MBITSET2INT(Char)
			MBITSET2INT(Int8)
			MBITSET2INT(Int16)
			MBITSET2INT(Int32)
			MBITSET2INT(Int64)
			MBITSET2INT(UInt8)
			MBITSET2INT(UInt16)
			MBITSET2INT(UInt32)
			MBITSET2INT(UInt64)


			//sequence to sequence

			//assoc to assoc

			//ptr to some
			//some to ptr

			//some to string
			//string to some

			//some to bool
			//bool to some

			//datetime to datetime
		}
	}
}

#endif
