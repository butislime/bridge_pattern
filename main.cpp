#include <iostream>
#include <string>

class Material {
	public:
		virtual std::string getMaterialName() = 0;
};
class Wood : public Material {
	public:
		std::string getMaterialName() override { return "Wood"; }
};
class Glass : public Material {
	public:
		std::string getMaterialName() override { return "Glass"; }
};

class Tableware {
	public:
		Tableware( Material* material ) : material_(material) {}
		virtual ~Tableware() { delete material_; }

		virtual void use() = 0;
	protected:
		Material* material_;
};
class Bowl : public Tableware {
	public:
		Bowl( Material* material ) : Tableware( material ) {}
		void use() override { std::cout << "Bowl : " << material_->getMaterialName() << std::endl; }
};
class Plate : public Tableware {
	public:
		Plate( Material* material ) : Tableware( material ) {}
		void use() override { std::cout << "Plate : " << material_->getMaterialName() << std::endl; }
};

int main()
{
	Tableware* tableware = new Bowl( new Wood );
	tableware->use();
	delete tableware;

	return 0;
}
