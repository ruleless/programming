#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <iterator>
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

#pragma warning(disable : 4267)

void ParseIn(const long double& _s, vector<int>& _vec_s, size_t& _factor)
{
	size_t found;
	stringstream ss;
	string str;
	int tmp;

	ss <<fixed ;
	ss <<_s;
	str = ss.str();

	// trim front 0s
	found =str.find_first_not_of('0');
	if(found!=string::npos) 
		str.erase(0,found);
	// trim back 0s
	found =str.find_last_not_of('0');
	if(found!=string::npos && found!=str.size()-1) 
		str.erase(found+1);
	// trim point
	found = str.find_first_of('.');
	if(found!=string::npos) 
	{
		_factor = str.size() - found - 1;
		str.erase(found, 1);
	}
	// trim front 0s again after trim point
	found =str.find_first_not_of('0');
	if(found!=string::npos && found!=0) 
		str.erase(0,found);

	for(size_t i=0; i<str.size(); ++i)
	{
		tmp = atoi(string(1,str[i]).c_str());
		_vec_s.push_back(tmp);
	}
	reverse(_vec_s.begin(), _vec_s.end());
}

void ParseOut(vector<int>& _vec_s, string& _str )
{
	size_t found;
	ostringstream oss;

	reverse(_vec_s.begin(), _vec_s.end());
	copy(_vec_s.begin()
		,_vec_s.end()
		,ostream_iterator<int>(oss));
	_str = oss.str();
	// trim front 0s
	found =_str.find_first_not_of('0');
	if(found!=string::npos) 
		_str.erase(0,found);
	//// trim back 0s
	//found =_str.find_last_not_of('0');
	//if(found!=string::npos && found!=_str.size()-1) 
	//	_str.erase(found+1);
}

vector<int> Mutiply(const vector<int>& _vec_a, const vector<int>& _vec_b)
{
	int carry;
	int tmp;
	vector<int> vec_ret(_vec_a.size() + _vec_b.size());
	if (1==_vec_a.size() && 1==_vec_a[0])
		return _vec_b;
	if (1==_vec_b.size() && 1==_vec_b[0])
		return _vec_a;

	for(size_t i =0; i<_vec_a.size(); ++i)
	{
		carry = 0;
		for(size_t j=0; j<_vec_b.size(); ++j)
		{
			tmp = vec_ret[i+j] + _vec_a[i] * _vec_b[j] +carry;
			vec_ret[i+j] = tmp%10;
			carry = tmp/10;
		}
		vec_ret[i+_vec_b.size()] = carry;
	}

	return vec_ret;
}

string ComputeExp(const long double& _s, const size_t& _n)
{
	vector<int> vec_s;
	vector<int> vec_d;
	stringstream ss;
	string str;
	size_t factor;
	int pos;

	ParseIn(_s, vec_s, factor);
	if (_s<numeric_limits<long double>::epsilon())
		return string("0");
	if (0==_n)
		return string("1");

	vec_d.push_back(1);
	for (size_t k=1; k<=_n; ++k)
		vec_d = Mutiply(vec_d, vec_s);

	ParseOut(vec_d, str);
	pos = str.size() - _n*factor;
	if (pos==str.size())
		return str;
	else if (pos>=0)
		str.insert(pos, ".");
	else
	{
		size_t count = static_cast<size_t>(abs(pos));
		str.insert(0, count, '0');
		str.insert(0, ".");
	}
	return str;
}

int main()
{
	long double s;
	size_t n;
	while(cin >>s >>n )
		cout <<ComputeExp(s, n) <<endl;
	return 0;
}

