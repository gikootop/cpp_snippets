#include <vector>
#include <algorithm>

class Observer
{
public:
	virtual ~Observer() {}

	virtual void onNotifierXXXXXXChanged() {}
};

class Notifier
{
public:

	/**
	 * @brief 添加观察者
	 * @param observer 观察者
	*/
	virtual void addObserver(Observer* observer);

	/**
	 * @brief 移除观察者
	 * @param observer 观察者
	*/
	virtual void removeObserver(Observer* observer);

private:
	virtual void notifyXXXXXXChanged();

	/** 观察者 */
	std::vector<Observer*> m_observers;
};

void Notifier::addObserver(Observer* observer)
{
	m_observers.push_back(observer);
}

void Notifier::removeObserver(Observer* observer)
{
	auto iter = std::find(m_observers.begin(), m_observers.end(), observer);
	if (iter != m_observers.end())
	{
		m_observers.erase(iter);
	}
}

void Notifier::notifyXXXXXXChanged()
{
	auto tmpVector = m_observers;
	for (auto item : tmpVector)
	{
		if (item)
		{
			item->onNotifierXXXXXXChanged();
		}
	}
}