package lego

import (
	uuid "github.com/satori/go.uuid"
)

// // Question data struct
// type Question struct {
// 	ID           string
// 	Title        string
// 	ResponseType int
// 	Description  string
// 	Order        int
// }

// // Page data struct
// type Page struct {
// 	ID        string
// 	Title     string
// 	Order     int
// 	Questions []*Question
// }

// // Template data struct
// type Template struct {
// 	ID    string
// 	Name  string
// 	Pages []*Page
// }

// DataGenerator type
type DataGenerator struct {
}

// DataGen is instance of DataGenerator
var DataGen *DataGenerator

func init() {
	DataGen = &DataGenerator{}
}

// GenerateData generates template data
func (g *DataGenerator) GenerateData() *Template {
	var pages []*Page
	var j int32
	var i int32
	for j = 0; j < 100; j++ {
		var questions []*Question

		for i = 0; i < 100; i++ {
			question := &Question{
				Id:           uuid.NewV4().String(),
				Title:        "Question title",
				ResponseType: 3,
				Description:  "This is the description for the question. This is the description for the question. This is the description for the question. This is the description for the question.",
				Order:        i,
			}
			questions = append(questions, question)
		}

		page := &Page{
			Id:        uuid.NewV4().String(),
			Title:     "Page title",
			Order:     j,
			Questions: questions,
		}
		pages = append(pages, page)
	}

	return &Template{
		Id:    uuid.NewV4().String(),
		Name:  uuid.NewV4().String(),
		Pages: pages,
	}
}
