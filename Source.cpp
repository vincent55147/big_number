#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct node {
	vector<int>num;
};
bool comparison2(node a, node b) {
	bool found=true;
	reverse(a.num.begin(), a.num.end());
	reverse(b.num.begin(), b.num.end());
	if (a.num.size() > b.num.size())
		return true;
	for (int i = 0; i <a.num.size(); i++) {
		if (a.num[i] == b.num[i])
			continue;
		if (a.num[i] > b.num[i]) {
			break;
		}
		else {
			found = false;
			break;
		}	
	}
	if (found) {
		found = false;
		for (int i = 0; i < a.num.size(); i++) {
			if (a.num[i] != b.num[i]) {
				found = true;
				break;
			}
		}
	}
	if (found)
		return true;
	return false;
}
bool comparison(node a,node b){
		bool found = true;
		reverse(a.num.begin(), a.num.end());
		reverse(b.num.begin(), b.num.end());
		if (a.num.size() > b.num.size())
			return true;
		if (a.num.size() < b.num.size())
			return false;
		for (int i = 0; i < a.num.size(); i++) {
			if (a.num[i] == b.num[i])
				continue;
			if (a.num[i] < b.num[i]) {
				found = false;
				break;
			}
			else
				break;
		}
		if (found) {
			found = false;
			for (int i = 0; i < a.num.size(); i++) {
				if (a.num[i] != b.num[i]) {
					found = true;
					break;
				}
			}
		}
		if (found)
			return true;
	return false;
}
node add2(node a, node b, int d) {
	int q, w, e = 0;
	node c;
	if (d>0)
		for (int i = 0; i < d; i++) {
			if (i < a.num.size())
				c.num.push_back(a.num[i]);
			else
				c.num.push_back(0);
		}

	for (int i = 0; i < max(a.num.size(), b.num.size()); i++) {
		if (i+d< a.num.size())
			q = a.num[i+d ];
		else
			q = 0;
		if (i < b.num.size())
			w = b.num[i];
		else
			w = 0;
		e = q + w + e;
		c.num.push_back(e % 10);
		e /= 10;
	}

	if (e != 0)
		c.num.push_back(e/10);
	return c;
}
node add(node a, node b) {
	int q, w,e=0;
	node c;
	for (int i = 0; i < max(a.num.size(), b.num.size()); i++) {
		if (i < a.num.size())
			q = a.num[i];
		else
			q = 0;
		if (i < b.num.size())
			w = b.num[i];
		else
			w = 0;
		e = q + w + e;
		c.num.push_back(e % 10);
		e /= 10;
	}
	if (e != 0)
		c.num.push_back(e / 10);
	while (c.num[c.num.size() - 1] == 0)
		c.num.pop_back();
	return c;
}
node subtract2(node a, node b) {
	int q, w, e = 0;
	node c;
reverse(a.num.begin(), a.num.end());
reverse(b.num.begin(), b.num.end());
for (int i = 0; i < max(a.num.size(), b.num.size()); i++) {
if (i < a.num.size())
	q = a.num[i];
else
q = 0;
if (i < b.num.size())
	w = b.num[i];
else
w = 0;
if (q >= w) {
	e = q - w;
	c.num.push_back(e);
	e = 0;
}
else {
	e = q + 10 - w;
	w = c.num.back();
	c.num.pop_back();
	c.num.push_back(w - 1);
	c.num.push_back(e);
}
}
reverse(c.num.begin(), c.num.end());
return c;
}
node subtract(node a, node b) {
	int q, w, e = 0;
	node c;
	for (int i = 0; i < max(a.num.size(), b.num.size()); i++) {
		if (i < a.num.size())
			q = a.num[i];
		else
			q = 0;
		if (i < b.num.size())
			w = b.num[i];
		else
			w = 0;
		q = q + e;
		if (q >= w) {
			e = q - w;
			c.num.push_back(e);
			e = 0;
		}
		else {
			e = q + 10 - w;
			c.num.push_back(e);
			e = -1;
		}
	}
	while (c.num[c.num.size() - 1] == 0)
		c.num.pop_back();
	return c;
}
node multiply(node a, node b) {
	int q, w, e = 0;
	node c, d;
	d.num.push_back(0);
	for (int i = 0; i < b.num.size(); i++) {
		q = b.num[i];
		c.num.clear();
		for (int h = 0; h < a.num.size(); h++) {
			w = a.num[h];
			e = w*q + e;
			c.num.push_back(e % 10);
			e /= 10;
		}
		while (e != 0) {
			c.num.push_back(e%10);
			e /= 10;
		}
		d = add2(d, c, i);
	}
	while (d.num.size() - 1 > 0 && d.num[d.num.size() - 1] == 0)
		d.num.pop_back();
	return d;
}
node divide(node a, node b) {
	int q=0, w = 0, h;
	node  c, d, f;
	d.num.push_back(0);
	if ( b.num.size()==1 && b.num.back()==0)
		return d;
	if (comparison(b,a))
		return d;
	int k = a.num.size() - b.num.size() + 1;
	for (int j = 1; j <= k; j++) {
		q += b.num.size();
		for (int i = 1; i <= 9; i++) {
			d.num.pop_back();
			d.num.push_back(i);
			f = multiply(b, d);
			if (f.num.size() >= q&& comparison2(f, a)) {
				if (j > k)
					break;
				if (i - 1 > 0) {
					c.num.push_back(i - 1);
					d.num.pop_back();
					d.num.push_back(i - 1);
					f = multiply(b, d);
					a = subtract2(a, f);
					w++;
					q = 0;
					break;
				}
				else {
					w++;
					q++;
					if (j-1 == c.num.size()) {
						int l = 0;
						c.num.push_back(0);
						j++;
						for (h = 0; h < w; h++) {
							if ((!a.num.empty()) && a.num.back() == 0) {
								a.num.pop_back();
								if (q > 0)
									q--;
							}
							else
								l++;
						}
						w -= h;
						w += l;
					}
				}
			}
			else if (i == 9) {
				c.num.push_back(i);
				q = 0;
				a = subtract2(a, f);
				w++;
				q = 0;
				break;
			}
		}
		for (h = 0; h < w; h++) {
			if ((!a.num.empty()) && a.num.back() == 0) {
				a.num.pop_back();
				if (q > 0)
					q--;
			}
			else
				q++;
		}
		w -= h;
	}
	reverse(c.num.begin(), c.num.end());
	while (c.num.size() - 1 > 0 && c.num[c.num.size() - 1] == 0)
		c.num.pop_back();
	return c;
}
node transform(string a) {
	node b;
	for (int i = a.size() - 1; i >= 0; i--)
		b.num.push_back(a[i] - '0');
	return b;
}
void print(node a) {
	for (int i = a.num.size() - 1; i >= 0; i--) {
		cout << a.num[i];
	}
	cout << endl;
}
int main() {
	string a, b;
	char c;
	node num1, num2,num3;
	while (cin >> a >> c >> b) {
		num1 = transform(a);
		num2 = transform(b);
		if (c == '+') {
			num3 = add(num1, num2);
			print(num3);
		}
		else if (c == '-') {
			if (comparison(num1, num2)) {
				num3 = subtract(num1, num2);
				print(num3);
			}
			else {
				num3 = subtract(num2, num1);
				cout << "-";
				print(num3);
			}
		}
		else if (c == '*') {
			num3 =multiply(num1,num2) ;
			print(num3);
		}
		else if (c == '>') {
			cout << comparison(num1, num2);
		}
		else {
			num3=divide(num1, num2);
			print(num3);
		}
	}
}