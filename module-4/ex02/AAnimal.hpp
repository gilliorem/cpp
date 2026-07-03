#include <string>

class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		~Brain();

		const std::string& getIdea(int index) const;
		void setIdea(const std::string& idea, int index);
};


class AAnimal
{
	protected:
		std::string type;
	
	public:
		AAnimal();
		AAnimal(const AAnimal& other);
		AAnimal& operator=(const AAnimal& other);
		virtual ~AAnimal();

		const std::string& getType() const;

		virtual void makeSound() const = 0;
};

class Dog: public AAnimal
{
	private:
		Brain* brain;
	public:
		Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		~Dog();

		void makeSound() const; // override
};

class Cat: public AAnimal
{
	private:
		Brain* brain;
	public:
		Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		~Cat();
		const std::string& getIdea(int index) const;
		void setIdea(const std::string& idea, int index);

		void makeSound() const; // override
};
