#pragma once
#include <QObject>
#include "XmlUtilsGlobal.h"
#include <QtXml>
#include <QDir>

JIN_BEGIN_NAMESPACE

class XMLUTILS_LIB_EXPORT XmlUtils
{
public:
	/**
	 * Adds an XML node
	 *
	 * \param [in]	   dom			   the xml dom.
	 * \param [in]	   parentNodeName  父节点.
	 * \param [in]	   nodeName		   当前节点名称.
	 * \param [in]	   attrNames	   List of names of the attributes.
	 * \param [in]	   attrs		   The attributes.
	 * \param [in]	   matchedAttrName 需要额外匹配的属性名称.
	 * \param [in]	   matchedContent  需要额外匹配的属性值.
	 *
	 * \returns A QDomElement.
	 */

	static QDomElement addXmlNode(QDomDocument *dom,
		const QString & parentNodeName,
		const QString & nodeName,
		QStringList attrNames,
		QStringList attrs,
		const QString &matchedAttrName,
		const QString & matchedContent);

	/**
	 * Adds an XML node
	 *
	 * \param [in]	   dom			   the xml dom.
	 * \param [in]	   parentNodeName  父节点.
	 * \param [in]	   nodeName		   当前节点名称.
	 * \param [in]	   attrNames	   List of names of the attributes.
	 * \param [in]	   attrs		   The attributes.
	 *
	 * \returns A QDomElement.
	 */

	static QDomElement addXmlNode(QDomDocument *dom,
		const QString & parentNodeName,
		const QString & nodeName,
		QStringList attrNames,
		QStringList attrs);

	/**
	 * Adds an text XML node
	 *
	 * \param [in]	   dom			   the xml dom.
	 * \param [in]	   parentNodeName  父节点.
	 * \param [in]	   nodeName		   当前节点名称.
	 * \param [in]	   nodeText	       节点文本值.
	 *
	 * \returns A QDomElement.
	 */

	static QDomElement addXmlNode(QDomDocument *dom,
		const QString & parentNodeName,
		const QString & nodeName,
		const QString & nodeText);

	/**
	 * Adds an text XML node
	 *
	 * \param [in]	   dom			   the xml dom.
	 * \param [in]	   parentNodeName  父节点.
	 * \param [in]	   nodeName		   当前节点名称.
	 * \param [in]	   nodeText	       节点文本值.
	 * \param [in]	   matchedAttrName 需要额外匹配的属性名称.
	 * \param [in]	   matchedContent  需要额外匹配的属性值.
	 *
	 * \returns A QDomElement.
	 */

	static QDomElement addXmlNode(QDomDocument *dom,
		const QString & parentNodeName,
		const QString & nodeName,
		const QString & nodeText,
		const QString & matchedNodeName,
		const QString & name);

	/**
	 * Adds an XML node attribute
	 *
	 * \param [in]	   dom			   the xml dom.
	 * \param [in]	   parentNodeName  父节点.
	 * \param [in]	   nodeName		   当前节点名称.
	 * \param [in]	   attrName	       属性名.
	 * \param [in]	   attr			   属性值.
	 */

	static void addXmlNodeAttr(QDomDocument * dom, const QString & nodeName,
		const QString &attrName, const QString &attr);

	/**
	 * Adds an XML node text
	 *
	 * \param [in]	   dom			   the xml dom.
	 * \param [in]	   parentNodeName  父节点.
	 * \param [in]	   nodeName		   当前节点名称.
	 * \param [in]	   text			   文本.
	 */

	static void addXmlNodeText(QDomDocument * dom,
		const QString & nodeName, const QString &text);

	/**
	 * 创建一个空节点。没有属性和文本
	 *
	 * \param [in]     dom	          the xml dom.
	 * \param [in]	   parentNodeName 父节点.
	 * \param [in]	   nodeName	      节点名称.
	 *
	 * \returns A nil QDomElement.
	 */

	static QDomElement addOneNilNode(QDomDocument * dom, const QString & parentNodeName,
		const QString & nodeName);

	/**
	 * Adds an one nil node
	 *
	 * \param [in]     dom	           the xml dom.
	 * \param [in]	   parentNodeName  父节点.
	 * \param [in]	   nodeName	       节点名称.
	 * \param [in]	   matchedAttrName 需要额外匹配的属性名称.
	 * \param [in]	   matchedContent  需要额外匹配的属性值.
	 *
	 * \returns A nil QDomElement.
	 */

	static QDomElement addOneNilNode(QDomDocument * dom,
		const QString & _parentNodeName,
		const QString & _nodeName,
		const QString & matchedAttrName,
		const QString & matchedContent);

	/**
	 * Deletes the node
	 *
	 * \param [in]     dom	           the xml dom.
	 * \param [in]	   nodeName	       节点名称.
	 *
	 * \returns True if it succeeds, false if it fails.
	 */

	static bool deleteNode(QDomDocument *dom, const QString & nodeName);

	/**
	 * Deletes the node
	 *
	 * \param [in]     dom	           the xml dom.
	 * \param [in]	   nodeName	       节点名称.
	 * \param [in]	   matchedAttrName 需要额外匹配的属性名称.
	 * \param [in]	   matchedContent  需要额外匹配的属性值.
	 *
	 * \returns True if it succeeds, false if it fails.
	 */

	static bool deleteNode(QDomDocument *dom, const QString & nodeName,
		const QString &matchedAttrName, const QString & matchedContent);

	/**
	 * Deletes the node attribute
	 *
	 * \param [in]     dom	           the xml dom.
	 * \param [in]	   nodeName	       节点名称.
	 * \param [in]	   attrName	       属性名称.			   
	 *
	 * \returns True if it succeeds, false if it fails.
	 */

	static bool deleteNodeAttr(QDomDocument *dom, const QString & nodeName, QString attrName);

	/**
	 * Modified node text content
	 *
	 * \param [in]     dom	           the xml dom.
	 * \param [in]	   nodeName	       节点名称.
	 * \param [in]	   newText	       文本.
	 *
	 * \returns True if it succeeds, false if it fails.
	 */

	static bool modifiedContent(QDomDocument *dom, const QString & nodeName, const QString &newText);

	/**
	 * Modified node attribute content
	 *
	 * \param [in]     dom	           the xml dom.
	 * \param [in]	   nodeName	       节点名称.
	 * \param [in]	   attrName	       属性名称.
	 * \param [in]	   newAttr	       属性值.
	 *
	 * \returns True if it succeeds, false if it fails.
	 */

	static bool modifiedContent(QDomDocument * dom, const QString & nodeName,
		const QString& attrName, const QString& newAttr);

	/**
	 * Modified content
	 *
	 * \param [in]     dom	           the xml dom.
	 * \param [in]	   nodeName	       节点名称.
	 * \param [in]	   matchedAttrName 需要额外匹配的属性名称.
	 * \param [in]	   matchedContent  需要额外匹配的属性值.
	 * \param [in]	   attrName	       属性名称.
	 * \param [in]	   newAttr	       属性值.
	 *
	 * \returns True if it succeeds, false if it fails.
	 */

	static bool modifiedContent(QDomDocument *dom, const QString & nodeName,
		const QString &matchedAttrName, const QString & matchedContent,
		const QString& attrName, const QString& newAttr);

	//! 添加xml处理指令*/
	static void appendRootXMLProcessingInstruction(QDomDocument *dom);

	/*! 添加root元素，并返回新添加的元素*/
	static QDomElement appendRootElement(QDomDocument *dom, QString name,
		QString& createTime = QString());

	//*!向已有的元素添加新的Dom元素,并返回新添加的元素*/
	static QDomElement appendDomElement(QDomElement &rDomElement, const QString elementName);

	/*!向已有的元素添加文本数据*/
	static QDomText appendText(QDomDocument *dom, QDomElement &rDomElement, 
		const QString &rText);

	/*!获取子dom元素，如果它不存在，则首先添加它*/
	static QDomElement getOrAppendNewDomElement(QDomElement &rDomElement, 
		const QString elementName);

	/*!添加包含一个文本节点的Dom元素*/
	static QDomElement appendDomTextNode(QDomElement &rDomElement, 
		const QString elementName, const QString text);

	/*!添加包含一个bool文本节点的Dom元素*/
	static QDomElement appendDomBooleanNode(QDomElement &rDomElement, 
		const QString elementName, const bool value);

	/*!用于添加包含一个文本节点的Dom元素(基于一个整数值)*/
	static QDomElement appendDomIntegerNode(QDomElement &rDomElement, 
		const QString elementName, const int val);

	/*!添加包含一个文本节点的Dom元素(基于一个浮点值)*/
	static QDomElement appendDomDoubleValueNode(QDomElement &rDomElement, \
		const QString elementName, \
		const double val, \
		const char format, \
		const int precision);

	/*!添加包含一个文本节点的Dom元素(基于两个浮点值)*/
	static QDomElement appendDomDoubleValueNode2(QDomElement &rDomElement, \
		const QString elementName, \
		const double a, \
		const double b, \
		const char format, \
		const int precision);

	/*!添加包含一个文本节点的Dom元素(基于N个浮点值)*/
	static QDomElement appendDomDoubleValueNodeN(QDomElement &rDomElement, \
		const QString elementName, \
		const QVector<double> &rValues, \
		const char format, \
		const int precision);

	/*!向Dom元素添加double (float或double)属性，同时确保小数点是"."而不是","*/
	static void setQrealAttribute(QDomElement domElement, \
		const QString attrName, \
		const double attrValue, \
		const int precision, \
		const char format);

	static QDomComment appendComment(QDomElement &rDomElement, const QString &rComment); /*!加注释*/

	/**@brief API for 解析xml*/
	static QDomElement loadXMLDomDocument(QFile &rFile, QDomDocument *domDocument, const QString& rootTagName, QString &error);

	/*!解析包含一个文本节点的一个DOM元素*/
	static QString parseDomTextNode(QDomElement domElement, const QString &rDefaultValue = "");

	/*!解析包含一个文本节点的一个DOM元素(基于3个浮点值)*/
	static void parseDomDoubleValueNode3(QDomElement &domElement, double &rA, double &rB, double &rC);

	/*!解析包含一个文本节点的一个DOM元素(基于2个浮点值)*/
	static void parseDomDoubleValueNode2(QDomElement &domElement, double &rA, double &rB);

	/*!解析包含一个文本节点的一个DOM元素(基于1个浮点值),传入一个默认值，当解析为空时返回默认值*/
	static double parseDomDoubleValueNode(QDomElement &domElement, const double defaultValue);

	/*!解析包含一个文本节点的一个DOM元素(基于1个整型值)，传入一个默认值，当解析为空时返回默认值*/
	static int parseDomIntegerNode(QDomElement &domElement, const int defaultValue);

	/*!解析包含一个文本节点的一个DOM元素(基于1个布尔值)，传入一个默认值，当解析为空时返回默认值*/
	static bool parseDomBooleanNode(QDomElement &domElement, const bool defaultValue);
	static bool parseAttributeBool(const QDomElement &domElement, const QString attributeName, const bool defaultValue);
	static void parseSimulationTimeTag(QDomElement &domElement, QString &rStart, QString &rStep, QString &rStop, bool &rInheritTs);

	static bool verifyProjectFileVersion(const QString & version);
	static bool verifySolutionFileVersion(const QString & version);
	static const QString generateCreateTime();

	static bool saveDom(QDomDocument* dom,const QString& savePath);
	
private:
	explicit XmlUtils() {}
};

JIN_END_NAMESPACE