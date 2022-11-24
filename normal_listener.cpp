class Listener
{
public:
	virtual ~Listener() {}
	
	virtual void onNotifierXXXXXXChanged() {}
};

class Notifier
{
public:

	/**
	 * @brief 添加监听者
	 * @param observer 监听者
	*/
	virtual void addListener(Listener* listener);
	
	/**
	 * @brief 移除监听者
	 * @param observer 监听者
	*/
	virtual void removeListener(Listener* listener);
	
private:
	virtual void notifyXXXXXXChanged();
	
	/** 监听者 */
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
		if (item)
		{
			item->onNotifierXXXXXXChanged();
		}
	}
}