#include "String.h"
#include <iostream>
#include <assert.h>

using namespace std;

namespace TheUltimateString
{
		String::String()
		{
			pData=NULL;
			elementsNum=0;
		}

		String::String(const String& string)
		{
			pData=NULL;
			copy(*this,string);
		}

		
		String::String(const char c, unsigned int t)
		{
			elementsNum=t;

			if(elementsNum==0)
			{
				pData=NULL;
				return;
			}

			pData=new char[elementsNum+1];
			for(unsigned int i=0;i<elementsNum;i++)
			{
				pData[i]=c;
			}
			pData[elementsNum]='\0';
		}


		void String::print(ostream& os)
		{
			for(unsigned int i=0;i<elementsNum;i++)
			{
				os<<pData[i];
			}
		}
		String::String(const char* str)
		{
			elementsNum = strlen(str);

			pData = new char[elementsNum + 1];

			for (int i = 0; i <= elementsNum; i++)
				pData[i] = str[i];
		}
		bool String::operator==(const String& other) const
		{
			if (elementsNum != other.elementsNum)
				return false;

			for (unsigned int i = 0; i < this->elementsNum; i++)

			{
				if (this->pData[i] != other.pData[i])
					return false;

			}
			return true;
		}
		char& String::operator[](unsigned int position)
		{
			static char ha = 0;
			if ((position < 0) || (position >= elementsNum))
				return ha;
			else
				return pData[position];
		}

		String String::concatenate(const String & string1, const String & string2)
		{
			String s;
			s.elementsNum=string1.elementsNum+string2.elementsNum;

			if(s.elementsNum==0)
			{
				s.pData=NULL;
				return s;
			}

			s.pData=new char[s.elementsNum+1];

			for(unsigned int i=0 ; i < string1.elementsNum ; i++)
			{
				s.pData[i]=string1.pData[i];
			}
			
			for(unsigned int j=string1.elementsNum; j < s.elementsNum; j++)
			{
				s.pData[j]=string2.pData[j - string1.elementsNum];
			}

			s.pData[s.elementsNum]='\0';
			return s;
		}

		bool String::compare(const String & string1, const String & string2)
		{
			if(string1.elementsNum!=string2.elementsNum)
				return false;

			for(unsigned int i=0;i<string1.elementsNum;i++)
			{
				if(string1.pData[i]!=string2.pData[i]) 
					return false;
			}
			return true;
		}
		const char& String::operator[](unsigned int position) const
		{
			if ((position < 0) || (position >= elementsNum))
				return char(0);
			else return
				pData[position];
		}

		void String::copy(String &string1, const String &string2)
		{
			delete string1.pData;	
			string1.elementsNum=string2.elementsNum;
			if(string1.elementsNum==0)
			{
				string1.pData=NULL;
				return;
			}
			string1.pData=new char[string1.elementsNum+1];
			for(unsigned int i=0;i<string1.elementsNum;i++)
			{
				string1.pData[i]=string2.pData[i];
			}
			string1.pData[string1.elementsNum]='\0';
		}

		
		String& String::operator+=(const String& theOther)
		{
			*this = concatenate(*this, theOther);
			return  *this;
		}
	
		bool String::operator!=(const String& other) const
		{
			if (elementsNum != other.elementsNum)
				return true;

			for (int i = 0; i < elementsNum; i++)

			{
				if (pData[i] != other.pData[i])
					return true;

			}
			return false;
		}

		String& String::operator=(const String& other)
		{
			copy(*this, other);
			return *this;
		}



		String::operator const char* () const
		{
			return pData;
		}

	


		
		String String::operator+(const String& other) const
		{
			return concatenate(*this, other);
		}


		
		
}