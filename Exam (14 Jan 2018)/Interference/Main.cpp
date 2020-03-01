#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

class Message
{
public:
	std::string frenq;
	std::vector<std::string> messageToDecomp;
	unsigned long priority = 0;
	bool messageReady = false;
	bool messageSent = false;
	std::string messageForPrint;

private:
	std::map<int, std::string> symbols;
	std::string messageDec;

private:
	void getPriority(std::string &m)
	{
		std::string number;
		bool numberFound = false;
		for (size_t i = 0; i < m.size(); i++)
		{
			if (isdigit(m[i]))
			{
				number += m[i];
				numberFound = true;
			}
			else
			{
				this->messageForPrint += m[i];
			}
		}
		if (numberFound)
		{
			unsigned long n = 0;
			n = std::stoul(number);
			this->priority = n;
		}
	}

public:
	void clearInterference()
	{
		size_t howManyBads = 0;
		for (size_t i = 0; i < messageToDecomp[0].size(); i++)
		{
			this->symbols[i] = messageToDecomp[0][i];
			if (messageToDecomp[0][i] == '?')
			{
				howManyBads++;
			}
		}

		for (size_t i = 0; i < messageToDecomp.size(); i++)
		{
			for (size_t a = 0; a < messageToDecomp[i].size(); a++)
			{
				if (symbols[a] == "?" && messageToDecomp[i][a] != '?')
				{
					this->symbols[a] = messageToDecomp[i][a];
					howManyBads--;
				}
			}
			if (howManyBads == 0) 
			{
				for (size_t k = 0; k < symbols.size(); k++)
				{
					this->messageDec += symbols[k];
				}
				this->symbols.clear();
				this->messageToDecomp.clear();

				this->getPriority(messageDec);
				this->messageReady = true;
				break;
			}
		}
	}
};



int main()
{
	std::vector<Message> allMessages;
	std::string userInputStr;
	std::stringstream ss;
	std::getline(std::cin, userInputStr);
	bool getFirstMessage = false;
	std::ostringstream info;

	while (userInputStr != "end")
	{
		ss << userInputStr;
		std::string word;
		bool getFreq = false;

		std::string wordOne = "";
		std::string wordTwo = "";

		Message message;
		while (ss >> word)
		{
			if (!getFirstMessage)
			{
				if (!getFreq)
				{
					getFreq = true;
					message.frenq = word;
				}
				else
				{
					message.messageToDecomp.push_back(word);
				}
			}
			else
			{
				if (word != "report")
				{
					if (!getFreq)
					{
						getFreq = true;
						wordOne = word;
					}
					else
					{
						wordTwo = word;
					}
				}
				else
				{
					// get report, if any exist!
					for (size_t i = 0; i < allMessages.size(); i++)
					{
						if (!allMessages[i].messageSent && !allMessages[i].messageReady)
						{
							allMessages[i].clearInterference();
						}					
					}
					std::sort(allMessages.begin(), allMessages.end(), [&allMessages](const Message& a, const Message& b) {return a.priority > b.priority; });
					bool noMessage = true;
					for (size_t j = 0; j < allMessages.size(); j++)
					{
						if (allMessages[j].messageReady && !allMessages[j].messageSent)
						{
							noMessage = false;
							allMessages[j].messageSent = true;
							info << allMessages[j].messageForPrint << "\n";
							break;
						}
					}
					if (noMessage)
					{
						info << "[no new messages]\n";
						break;
					}									
				}
			}

		}
		if (!getFirstMessage)
		{
			allMessages.push_back(message);
			getFirstMessage = true;
		}
		else
		{
			if (word != "report")
			{
				bool findFreq = false;
				bool exist = false;
				for (size_t i = 0; i < allMessages.size(); i++)
				{
					if (allMessages[i].frenq == wordOne && !allMessages[i].messageReady)
					{
						findFreq = true;
						allMessages[i].messageToDecomp.push_back(wordTwo);
						break;
					}
					if (allMessages[i].frenq == wordOne)
					{
						exist = true;
					}
				}
				if (!findFreq && !exist)
				{
					message.frenq = wordOne;
					message.messageToDecomp.push_back(wordTwo);
					allMessages.push_back(message);
				}
			}

		}

		ss.clear();
		ss.str(std::string(""));
		std::getline(std::cin, userInputStr);	
	}
	std::cout << info.str();

	return 0;
}
