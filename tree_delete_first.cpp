#include<iostream>
#include<memory>
struct node {
	int data;
	std::unique_ptr<node> port;
	std::unique_ptr<node> starboard;
	node(int a) {
		data = a;
		port = nullptr;
		starboard = nullptr;
	}
};
std::unique_ptr<node> root;
int max = 0;

class make {
public:
	node* helper;
	make()
	{
		helper = nullptr;
		root = nullptr;
	}
	void add(int a)
	{
		auto in = std::make_unique<node>(a);
		max++;
		if (root == nullptr) {
			root = std::move(in);
			helper = in.get();
		}
		else
		{
			helper = root.get();
			int u = 0, p = 0;
			bool sr, pr;
			while (true)
			{
				sr = false;
				pr = false;
				u = 0;
				while (a <= helper->data && helper->port && max > u)
				{
					helper = helper->port.get();
					u++;
					pr = true;

				}
				p = 0;
				while (a > helper->data && helper->starboard && max > p)
				{
					helper = helper->starboard.get();
					p++;
					sr = true;

				}
				if (!(pr || sr)) { break; }


			}


			if (a <= helper->data)
			{
				helper->port = std::move(in);
				return;
			}
			if (a > helper->data)
			{
				helper->starboard = std::move(in);
			}
		}

	}
};
class support {
public:

	void pre(node* ancor) {
		if (ancor) {
			int i = 0;
			node* kanan, * kiri;
			std::cout << ancor->data << " ";
			if (ancor->port && i < max) {
				kiri = ancor;
				kiri = kiri->port.get();
				i++;
				pre(kiri);
			}
			if (ancor->starboard && i < max) {
				kanan = ancor;
				kanan = kanan->starboard.get();
				i++;
				pre(kanan);
			}
		}

	}
	void in(node* ancor) {
		if (ancor) {
			node* kanan, * kiri;
			if (ancor->port) {
				kiri = ancor;
				kiri = kiri->port.get();
				in(kiri);
			}
			std::cout << ancor->data << " ";
			if (ancor->starboard) {
				kanan = ancor;
				kanan = kanan->starboard.get();
				in(kanan);
			}
		}
	}
	void las(node* ancor) {
		if (ancor) {
			node* kanan, * kiri;
			if (ancor->port) {
				kiri = ancor;
				kiri = kiri->port.get();
				las(kiri);
			}
			if (ancor->starboard) {
				kanan = ancor;
				kanan = kanan->starboard.get();
				las(kanan);
			}
			std::cout << ancor->data << " ";
		}
	}
	bool binary(int a) {
		node* bantu;
		bantu = root.get();
		if (bantu->data == a) { return true; }
		int i = 0;
		while (max > i)
		{
			if (bantu->data >= a && bantu->port) { bantu = bantu->port.get(); }
			if (bantu->data < a && bantu->starboard) { bantu = bantu->starboard.get(); }
			if (bantu->data == a) { return true; }
			i++;
		}
		return false;
	}
};
class penghapusan {
public:
	void dellete(int a)
	{
		node* bantu = root.get();
		node* temp = nullptr;
		std::unique_ptr<node> safe;
		int i = 0;

		while (max > i)
		{
			if (bantu->data >= a && bantu->port) { temp = bantu; bantu = bantu->port.get(); }
			if (bantu->data < a && bantu->starboard) { temp = bantu; bantu = bantu->starboard.get(); }
			if (bantu->data == a) { break; }
			i++;
		}
		//hapus selain akhir
		if (bantu->starboard || bantu->port)
		{
			node* bantunode = bantu;
			node* tempnode = nullptr;
			bool h = false, s = true, p = true;
			while (true)
			{
				s = false;
				p = false;
				while (bantunode->starboard)
				{
					tempnode = bantunode;
					bantunode = bantunode->starboard.get();
					h = true;
					s = true;

				}
				while (bantunode->port)
				{
					tempnode = bantunode;
					bantunode = bantunode->port.get();
					h = false;
					p = true;

				}
				if (!(p || s))
				{
					break;

				}

			}

			if (tempnode->data != a) 
			{

				if (temp->port->data == bantu->data)
				{
					if (!h)
					{
						bantunode->port = std::move(bantu->port);
						bantunode->starboard = std::move(bantu->starboard);
						temp->port = std::move(tempnode->port);

					}
					else
					{
						bantunode->port = std::move(bantu->port);
						bantunode->starboard = std::move(bantu->starboard);
						temp->port = std::move(tempnode->starboard);
					}
				}

				else
				{

					if (!h)
					{
						bantunode->port = std::move(bantu->port);
						bantunode->starboard = std::move(bantu->starboard);
						temp->starboard = std::move(tempnode->port);
					}
					else
					{
						bantunode->port = std::move(bantu->port);
						bantunode->starboard = std::move(bantu->starboard);
						temp->starboard = std::move(tempnode->starboard);

					}
				}

			}
			//hapus akhir
			else
			{
				if (tempnode->starboard->data > temp->data)
				{

					tempnode->starboard->port = std::move(tempnode->port);
					temp->starboard = std::move(tempnode->starboard);


				}
				else
				{
					tempnode->starboard->port = std::move(tempnode->port);
					temp->port = std::move(tempnode->starboard);

				}

			}
		}
		else 
		{
			if (temp->starboard->data == bantu->data) 
			{
				temp->starboard = nullptr;
		
			}
			else 
			{
				temp->port = nullptr;
			}

		}
	}


};
int main() {
	make in;
	support su;
	penghapusan dell;
	in.add(20);
	in.add(10);
	in.add(28);
	in.add(6);
	in.add(15);
	in.add(35);
	in.add(8);
	in.add(2);
	in.add(7);
	in.add(40);
	in.add(12);
	in.add(9);
	in.add(25);
	in.add(26);
	in.add(27);
	in.add(41);
	std::cout << max << std::endl;
	dell.dellete(8);
	std::cout << "\npre order \n : ";
	su.pre(root.get());
	std::cout << "\ninorder \n : ";
	su.in(root.get());
	std::cout << "\nlastorder \n : ";
	su.las(root.get());
	std::cout << std::endl;
	std::cout << su.binary(47);
}