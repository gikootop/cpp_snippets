class Observer
{
public:
	virtual ~Observer() {}
	
	virtual void onNotifierXXXXXXChanged() {}
};

class Notifier
{
public:
	virtual void addObserver(Observer* Observer);
	virtual void removeObserver(Observer* Observer);
	
private:
	virtual void notifyXXXXXXChanged();
	
	std::vector<Observer*> m_Observers;
};

void Notifier::addObserver(Observer* Observer)
{
	m_Observers.push_back(Observer);
}

void Notifier::removeObserver(Observer* Observer)
{
	auto iter = std::find(m_Observers.begin(), m_Observers.end(), Observer);
	if (iter != m_Observers.end())
	{
		m_Observers.erase(iter);
	}
}

void Notifier::notifyXXXXXXChanged()
{
	auto tmpVector = m_Observers;
	for (auto item : tmpVector)
	{
		if (*item)
		{
			(*item)->onNotifierXXXXXXChanged();
		}
	}
}