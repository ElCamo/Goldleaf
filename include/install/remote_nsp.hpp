#pragma once

#include <functional>
#include <vector>

#include <switch.h>
#include "install/pfs0.hpp"
#include "nx/ncm.hpp"
#include "util/network_util.hpp"

namespace tin::install::nsp
{
    class RemoteNSP
    {
        protected:
            std::vector<u8> m_headerBytes;

            RemoteNSP();

        public:
            virtual void RetrieveHeader() = 0;
            virtual void StreamToPlaceholder(nx::ncm::ContentStorage& contentStorage, NcmNcaId placeholderId) = 0;
    
            virtual const PFS0BaseHeader* GetBaseHeader();
            virtual u64 GetDataOffset();

            virtual const PFS0FileEntry* GetFileEntry(unsigned int index);
            virtual const PFS0FileEntry* GetFileEntryByName(std::string name);
            virtual const PFS0FileEntry* GetFileEntryByNcaId(const NcmNcaId& ncaId);
            virtual const PFS0FileEntry* GetFileEntryByExtension(std::string extension);

            virtual const char* GetFileEntryName(const PFS0FileEntry* fileEntry);
    };
}