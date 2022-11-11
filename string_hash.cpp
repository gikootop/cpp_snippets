// DJB Hash算法
size_t string_hash(const char* str)
{
	size_t hash = 5381;
	while (*str)
		hash = ((hash << 5) + hash) + (*str++);
	return  hash;
}