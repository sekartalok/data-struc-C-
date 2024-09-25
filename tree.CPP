#include<iostream>
#include<memory>

using namespace std;

struct node {
	int data;
	unique_ptr<node> port;
	unique_ptr<node> starboard;
	node(int a) {
		data = a;
		port = nullptr;
		starboard = nullptr;
	}
};

unique_ptr<node> root;

class make {
public:
	node* helper;
	make() {
		helper = nullptr;
		root = nullptr;
	}

	void call(int a) {
		auto in = make_unique<node>(a);
		if (root == nullptr) {
			root = move(in);
			helper = in.get();


		}
		else
		{
			helper = root.get();
			while (helper->port && helper->starboard)
			{
				if (a <= helper->data && helper->port) {
					helper = helper->port.get();
				}
				if (a > helper->data && helper->starboard) {
					helper = helper->starboard.get();
				}
			}
			if (a <= helper->data) {
				helper->port = std::move(in);
			}
			if (a > helper->data) {
				helper->starboard = std::move(in);
			}



		}
	}
};
class support {
public:

	void pre(node* ancor) {
		if (ancor) {
			node* kanan, * kiri;
			cout << ancor->data<<" ";


			if (ancor->port) {
				kiri = ancor;
				kiri = kiri->port.get();

				pre(kiri);
			}
			if (ancor->starboard) {
				kanan = ancor;
				kanan = kanan->starboard.get();

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

				pre(kiri);
			}
			std::cout << ancor->data<<" ";
			if (ancor->starboard) {
				kanan = ancor;
				kanan = kanan->starboard.get();

				pre(kanan);
			}
		}
	}
	void las(node* ancor) {
		if (ancor) {
			node* kanan, * kiri;
			if (ancor->port) {
				kiri = ancor;
				kiri = kiri->port.get();

				pre(kiri);
			}
			if (ancor->starboard) {
				kanan = ancor;
				kanan = kanan->starboard.get();

				pre(kanan);
			}	
			cout << ancor->data<<" ";
		}
	}


	bool binary(int a) {
		node* bantu;
		bantu = root.get();

		while (bantu->starboard && bantu->port)
		{
			if (bantu->data == a) { return true; }
			if (bantu->data >= a && bantu->port) { bantu = bantu->port.get(); }
			if (bantu->data < a && bantu->starboard) { bantu = bantu->starboard.get(); }
		}
		return false;
	}

};
int main() {
	make in;
	support su;
	in.call(20);
	in.call(10);
	in.call(28);
	in.call(6);
	in.call(15);
	in.call(35);
	in.call(8);
	in.call(2);
	in.call(7);
	in.call(40);
	in.call(12);
	in.call(9);
	in.call(25);
	cout << "pre order \n : ";
	su.pre(root.get());
	cout << "\ninorder \n : ";
	su.in(root.get());
	cout << "\nlastorder \n : ";
	su.las(root.get());
	cout << std::endl;
	cout << su.binary(3);
}
