#include "VirtualFileSystem.h"

namespace Kinemo 
{
	std::unordered_map<std::string, std::string> VFS::m_MountPoints = {};

	void VFS::Mount(const std::string& path,const std::string& name)
	{
		m_MountPoints[name] = path;
	}
}