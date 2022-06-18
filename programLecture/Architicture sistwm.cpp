// Шаблон Комманд 
#include <vector>
#include <string>
#include <iostream>

class Light{
public: 
	void on() {
		//logic
	}

	void off()
	{
		//logic
	}
};

class IComand {
public:
	virtual ~IComand() {}
	virtual void execute() = 0;
	virtual void unexecute() = 0;
protected:
	IComand(Light* l): lig(l){}
	Light* lig;
};

class OnLight : public IComand {
public:
	OnLight(Light* l) : IComand(l) {}

	void execute() {
		lig->on();
	}
	void unexecute() {
		lig->off();
	}
};


class OffLight : public IComand {
public:
	OffLight(Light* l) : IComand(l) {}

	void execute() {
		lig->off();
	}
	void unexecute() {
		lig->on();
	}
};


class Invoker{
	std::vector<IComand*> stack;

public:
	void front_command() {
		for (int i = 0; i < stack.size(); ++i) {
			stack[i]->execute();
		}
	}

	void back_command(){
		for (int i = stack.size(); i > 0; --i) {
			stack[i]->unexecute();
		}
	}

	void add_new_command(IComand* new_command) {
		stack.push_back(new_command);
	}
}


// Шаблон стратегия

// Иерархия классов, определяющая алгоритмы сжатия файлов
class Compression
{
public:
    virtual ~Compression() {}
    virtual void compress(const std::string& file) = 0;
};

class ZIP_Compression : public Compression
{
public:
    void compress(const std::string& file) {
        std::cout << "ZIP compression" << std::endl;
    }
};

class ARJ_Compression : public Compression
{
public:
    void compress(const std::string& file) {
        std::cout << "ARJ compression" << std::endl;
    }
};

class RAR_Compression : public Compression
{
public:
    void compress(const std::string& file) {
        std::cout << "RAR compression" << std::endl;
    }
};


// Класс для использования
class Compressor
{
public:
    Compressor(Compression* comp) : p(comp) {}
    ~Compressor() { delete p; }
    void compress(const std::string& file) {
        p->compress(file);
    }
private:
    Compression* p;
};

// Шаблон Адаптер

class FahrenheitSensor
{
public:
    // Получить показания температуры в градусах Фаренгейта
    float getFahrenheitTemp() {
        float t = 32.0;
        // logic
        return t;
    }
};

class Sensor
{
public:
    virtual ~Sensor() {}
    virtual float getTemperature() = 0;
};

class Adapter : public Sensor
{
public:
    Adapter(FahrenheitSensor* p) : p_fsensor(p) {
    }
    ~Adapter() {
        delete p_fsensor;
    }
    float getTemperature() {
        return (p_fsensor->getFahrenheitTemp() - 32.0) * 5.0 / 9.0;
    }
private:
    FahrenheitSensor* p_fsensor;
};

// Шаблон Vision

class Zoo;
class Cinema;

class IVisitor {
public:
	virtual void visit(Zoo& data) = 0;
	virtual void visit(Cinema& data) = 0;

	virtual ~IVisitor() = default;
};

class Place {
public:
	virtual void accept(IVisitor& v) = 0;
	virtual ~Place() = default;
};

class Zoo : public Place {
public:
	void accept(IVisitor& v) override {
		v.visit(*this);
	}
};

class Cinema : public Place {
public:
	void accept(IVisitor& v) override {
		v.visit(*this);
	}
};


class Day : public IVisitor {
public:
	std::string my_info;

	void visit(Zoo& v) override {
		my_info = "МАМОНТ БЛЯТЬ";
	}

	void visit(Cinema& v) override {
		my_info = "ПОРНО БЛЯТЬ";
	}
};



