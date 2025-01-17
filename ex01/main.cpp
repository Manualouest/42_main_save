/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:02:38 by mbirou            #+#    #+#             */
/*   Updated: 2025/01/17 17:40:44 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <spellBook.hpp>

int	main(void)
{
	Data		importantOperationData(1, "very classified operation documents");
	Data		BadOperationData(2, "toilet paper bills");
	uintptr_t	importantBytes = Serializer::serialize(&importantOperationData);
	Data		importantDeserializedData = *Serializer::deserialize(importantBytes);

	if (importantDeserializedData == importantOperationData)
		PRINT GRN BOLD "The operation may continue. 🕴️" CENDL;
	else
		PRINT RED BOLD "The operation has failed. 🕴️" CENDL;
	PRINT importantOperationData AND importantDeserializedData;

	NEWL;

	if (importantDeserializedData == BadOperationData)
		PRINT GRN BOLD "The operation may continue. 🕴️" CENDL;
	else
		PRINT RED BOLD "The operation has failed. 🕴️" CENDL;
	PRINT BadOperationData AND importantDeserializedData;
}