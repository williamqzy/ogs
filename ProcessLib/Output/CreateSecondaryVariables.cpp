/**
 * \file
 * \copyright
 * Copyright (c) 2012-2019, OpenGeoSys Community (http://www.opengeosys.org)
 *            Distributed under a Modified BSD License.
 *              See accompanying file LICENSE.txt or
 *              http://www.opengeosys.org/project/license
 *
 */

#include "CreateSecondaryVariables.h"

#include "BaseLib/ConfigTree.h"
#include "NumLib/NamedFunctionCaller.h"

#include "SecondaryVariable.h"

namespace ProcessLib
{
void createSecondaryVariables(
    BaseLib::ConfigTree const& config,
    SecondaryVariableCollection& secondary_variables,
    NumLib::NamedFunctionCaller& /*named_function_caller*/)
{
    auto sec_vars_config =
        //! \ogs_file_param{prj__processes__process__secondary_variables}
        config.getConfigSubtreeOptional("secondary_variables");
    if (!sec_vars_config)
    {
        return;
    }

    for (
        auto sec_var_config :
        //! \ogs_file_param{prj__processes__process__secondary_variables__secondary_variable}
        sec_vars_config->getConfigSubtreeList("secondary_variable"))
    {
        auto const type =
            //! \ogs_file_attr{prj__processes__process__secondary_variables__secondary_variable__type}
            sec_var_config.getConfigAttribute<std::string>("type");

        auto const internal_name =
            //! \ogs_file_attr{prj__processes__process__secondary_variables__secondary_variable__internal_name}
            sec_var_config.getConfigAttribute<std::string>("internal_name");
        auto const output_name =
            //! \ogs_file_attr{prj__processes__process__secondary_variables__secondary_variable__output_name}
            sec_var_config.getConfigAttribute<std::string>("output_name");

        secondary_variables.addNameMapping(internal_name, output_name);
    }
}

}  // namespace ProcessLib
