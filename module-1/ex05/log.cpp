#include <string>
#include <iostream>

class Log
{
	private:
		enum msgType
		{
			INFO,
			WARNING,
			ERROR,
		};
		void info()
		{
			std::cout << "[INFO] this is an info log message\n";
		}
		void warning()
		{
			std::cout << "[WARNING] This is a warning message\n";
		}
		void error()
		{
			std::cout << "[ERROR] This is an error message\n";
		}
	public:

		int getLogCode(std::string context)
		{
			struct Pair
			{
				std::string context;
				int msgType;
			};
			Pair table[] = {
				{"color=dark", INFO},
				{"warning", WARNING},
				{"void fun", ERROR},
			};
			
			for (int i = 0; i < 3; i++)
			{
				if (table[i].context == context)
					return table[i].msgType;
			}
			return (-1);
		}

		void print(int msgType)
		{
			struct Pair
			{
				int msgType;
				void (Log::*fun)(void);
			};

			Pair table[] = {
				{INFO, &Log::info },
				{WARNING, &Log::warning },
				{ERROR, &Log::error },
			};

			for (int i = 0; i < 3; i++)
			{
				if (table[i].msgType == msgType)
				{
					(this->*table[i].fun)();
					return ;
				}
			}
			std::cout << "Unknown msg type\n";
		}
};

int main()
{
	Log logger;

	int errorCode = logger.getLogCode("color=dark");
	logger.print(errorCode);

}
