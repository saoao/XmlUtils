#pragma once

#include "gtest/gtest.h"
#include "XmlUtils.h"

TEST(XmlUtilsTest, f_testXmlUtilsFunc)
{
	QDomDocument dom;
	XmlUtils::appendRootXMLProcessingInstruction(&dom);
	XmlUtils::appendRootElement(&dom,"rootNode");
	XmlUtils::addXmlNode(&dom, "rootNode", "childNode", { "name","age" }, { "xiaoming","20" });
	XmlUtils::addXmlNode(&dom, "rootNode", "childNode2", { "name","age" }, { "xiaohong","21" });
	XmlUtils::addXmlNode(&dom, "rootNode", "childNode2", { "name","age" }, { "xiaodong","22" });
	XmlUtils::deleteNode(&dom, "childNode2","name","xiaohong");

	XmlUtils::modifiedContent(&dom, "childNode", "age", "30");

	XmlUtils::saveDom(&dom, "test.xml");
}