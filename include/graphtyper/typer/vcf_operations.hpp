#pragma once

#include <string>
#include <vector>


namespace gyper
{

void vcf_merge(std::vector<std::string> & vcfs, std::string const & output);
void vcf_concatenate(std::vector<std::string> const & vcfs, std::string const & output, bool const SKIP_SORT, bool const SITES_ONLY, std::string const & region);
void vcf_break_down(std::string const & vcf, std::string const & output, std::string const & region);
void vcf_update_info(std::string const & vcf, std::string const & output);

} // namespace gyper
