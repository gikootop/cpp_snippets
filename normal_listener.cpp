class Listener
{
public:
	virtual ~Listener() {}
	
	virtual void onNotifierXXXXXXChanged() {}
};

class Notifier
{
public:
	virtual void addListener(Listener* listener);
	virtual void removeListener(Listener* listener);
	
private:
	virtual void notifyXXXXXXChanged();
	
	std::vector<Listener*> m_listeners;
};

void Notifier::addListener(Listener* listener)
{
	m_listeners.push_back(listener);
}

void Notifier::removeListener(Listener* listener)
{
	auto iter = std::find(m_listeners.begin(), m_listeners.end(), listener);
	if (iter != m_listeners.end())
	{
		m_listeners.erase(iter);
	}
}

void Notifier::notifyXXXXXXChanged()
{
	auto tmpVector = m_listeners;
	for (auto item : tmpVector)
	{
		if (*item)
		{
			(*item)->onNotifierXXXXXXChanged();
		}
	}
}