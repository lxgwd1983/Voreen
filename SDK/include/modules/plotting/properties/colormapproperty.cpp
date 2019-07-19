/***********************************************************************************
 *                                                                                 *
 * Voreen - The Volume Rendering Engine                                            *
 *                                                                                 *
 * Copyright (C) 2005-2013 University of Muenster, Germany.                        *
 * Visualization and Computer Graphics Group <http://viscg.uni-muenster.de>        *
 * For a list of authors please refer to the file "CREDITS.txt".                   *
 *                                                                                 *
 * This file is part of the Voreen software package. Voreen is free software:      *
 * you can redistribute it and/or modify it under the terms of the GNU General     *
 * Public License version 2 as published by the Free Software Foundation.          *
 *                                                                                 *
 * Voreen is distributed in the hope that it will be useful, but WITHOUT ANY       *
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR   *
 * A PARTICULAR PURPOSE. See the GNU General Public License for more details.      *
 *                                                                                 *
 * You should have received a copy of the GNU General Public License in the file   *
 * "LICENSE.txt" along with this file. If not, see <http://www.gnu.org/licenses/>. *
 *                                                                                 *
 * For non-commercial academic use see the license exception specified in the file *
 * "LICENSE-academic.txt". To get information about commercial licensing please    *
 * contact the authors.                                                            *
 *                                                                                 *
 ***********************************************************************************/

#include "colormapproperty.h"
#include "voreen/core/properties/condition.h"

#include <sstream>

namespace voreen {

ColorMapProperty::ColorMapProperty(const std::string& id, const std::string& guiText,
                     ColorMap value, Processor::InvalidationLevel invalidationLevel)
    : TemplateProperty<ColorMap>(id, guiText, value, invalidationLevel)
{}

void ColorMapProperty::serialize(XmlSerializer& s) const {
    Property::serialize(s);

    s.serialize("colors", value_);
}

void ColorMapProperty::deserialize(XmlDeserializer& s) {
    Property::deserialize(s);

    ColorMap cm = ColorMap::createColdHot();
    s.deserialize("colors", cm);
    try {
        value_ = cm;
    }
    catch (Condition::ValidationFailed& e) {
        s.addError(e);
    }
}

std::string ColorMapProperty::getTypeDescription() const {
    return "ColorMap";
}

}   // namespace
